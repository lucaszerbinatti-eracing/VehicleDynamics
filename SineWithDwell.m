%% Sine with Dwell Test (ISO 19365 / FMVSS 126) - Velocity-Based
clear; clc; close all;

set_param('PlanarModelandControl/Subsystem/Driver', 'Commented', 'on');
set_param('PlanarModelandControl/Subsystem/Driver2', 'Commented', 'off');


modelo = 'PlanarModelandControl';
load_system(modelo);



%% 1. PARAMETERS
velocities  = [10, 15];      % [m/s]
amplitudes  = [15, 30, 60];  % [deg] Steering wheel angle
freq        = 0.7;           % [Hz] (FMVSS 126 Standard)
t_dwell     = 0.5;           % [s]  (500ms Dwell time)
t_pre       = 0.5;           % [s]  Initial straight coast
t_post      = 3.0;           % [s]  Final observation window (coastdown)

% Calculation of exact maneuver phase timings
T_period = 1 / freq;
T_3q = 0.75 * T_period;      % 3/4 of the sine cycle
T_1q = 0.25 * T_period;      % Final 1/4 cycle (return to center)
t_end_maneuver = t_pre + T_3q + t_dwell + T_1q;
total_time     = t_end_maneuver + t_post;

% Command time vector (named t_cmd to avoid conflicts with Simulink's 't')
t_cmd = (0:0.01:total_time)';

% Fixed commands (FMVSS 126 requires the maneuver to be performed in throttle-off/coastdown)
assignin('base', 'Accel_Cmd', [t_cmd, zeros(size(t_cmd))]);
assignin('base', 'Brake_Cmd', [t_cmd, zeros(size(t_cmd))]);
assignin('base', 'Flag_CruiseControl', 1);
assignin('base', 'Controles_Ativos', 1);
assignin('base', 'GG_mode', 0);

% Color palette for different steer amplitudes
plot_colors = lines(length(amplitudes));

%% 2. SIMULATION LOOP
for v = velocities
    % Update initial and reference velocity
    assignin('base', 'Vx_Ref', v);
    assignin('base', 'Vx_init', v);
    
    fig = figure('Name', sprintf('Sine with Dwell - V = %d m/s', v), 'Color', 'w', ...
                 'Position', [100 100 900 700]);
    fprintf('\n--- Testing V0 = %d m/s ---\n', v);
    
    for i = 1:length(amplitudes)
        a = amplitudes(i);
        current_color = plot_colors(i, :);
        
        % --- VECTORIZED STEERING INPUT CONSTRUCTION (SINE WITH DWELL) ---
        w = 2 * pi * freq;
        t1 = t_pre;              % Start of steering
        t2 = t1 + T_3q;          % End of the first 3/4 wave
        t3 = t2 + t_dwell;       % End of the dwell period
        t4 = t3 + T_1q;          % End of maneuver (return to 0)
        
        steer = zeros(size(t_cmd));
        idx_s1 = t_cmd >= t1 & t_cmd < t2;
        idx_dw = t_cmd >= t2 & t_cmd < t3;
        idx_s2 = t_cmd >= t3 & t_cmd <= t4;
        
        steer(idx_s1) = a * sin(w * (t_cmd(idx_s1) - t1));
        steer(idx_dw) = -a; % Hold at second peak (sin 270° = -1)
        steer(idx_s2) = a * sin(w * (t_cmd(idx_s2) - t1 - t_dwell));
        
        assignin('base', 'Steer_Cmd', [t_cmd, steer]);
        
        % Run simulation
        out = sim(modelo, 'StopTime', num2str(total_time));
        
        % Extract data (Format: Structure with Time)
        t_sim   = out.v_yaw.time; 
        yaw     = rad2deg(out.v_yaw.signals.values);
        yaw_ref = rad2deg(out.Yaw_des.signals.values); 
        vx      = out.Vx_out.signals.values;
        
        % --- FMVSS 126 REGULATORY METRICS CALCULATION ---
        peak_yaw = max(abs(yaw));
        
        % Interpolate exact yaw rate at t_end + 1.0s and t_end + 1.75s
        t_100 = t_end_maneuver + 1.00;
        t_175 = t_end_maneuver + 1.75;
        yaw_100 = interp1(t_sim, abs(yaw), t_100, 'linear', NaN);
        yaw_175 = interp1(t_sim, abs(yaw), t_175, 'linear', NaN);
        
        ratio_100 = (yaw_100 / peak_yaw) * 100;
        ratio_175 = (yaw_175 / peak_yaw) * 100;
        
        % Compliance check
        res_100 = 'FAIL'; if ratio_100 <= 35, res_100 = 'PASS'; end
        res_175 = 'FAIL'; if ratio_175 <= 20, res_175 = 'PASS'; end
        
        % Console output in Technical English
        fprintf('Steering: %3d deg | Peak: %5.1f deg/s | @1.0s: %4.1f%% (%s) | @1.75s: %4.1f%% (%s)\n', ...
                a, peak_yaw, ratio_100, res_100, ratio_175, res_175);
                
        % --- PLOTTING FOR CURRENT FIGURE ---
        figure(fig);
        legend_name = sprintf('%d deg', a);
        
        % 1. Steering Wheel Angle
        subplot(3,1,1); hold on; grid on;
        plot(t_cmd, steer, 'Color', current_color, 'LineWidth', 1.5, 'DisplayName', legend_name);
        
        % 2. Yaw Rate (Solid = Actual, Dashed = Reference)
        subplot(3,1,2); hold on; grid on;
        plot(t_sim, yaw, 'Color', current_color, 'LineWidth', 1.5, 'HandleVisibility', 'off');
        plot(t_sim, yaw_ref, '--', 'Color', current_color, 'LineWidth', 1.2, 'HandleVisibility', 'off');
        
        % Visual time markers for regulatory criteria
        xline(t_100, ':', 'Color', current_color, 'HandleVisibility', 'off');
        xline(t_175, ':', 'Color', current_color, 'HandleVisibility', 'off');
        
        % 3. Longitudinal Velocity (Coastdown)
        subplot(3,1,3); hold on; grid on;
        plot(t_sim, vx, 'Color', current_color, 'LineWidth', 1.5, 'HandleVisibility', 'off');
    end
    
    % --- FORMATTING THE CURRENT VELOCITY FIGURE ---
    figure(fig);
    
    subplot(3,1,1); 
    title(sprintf('Sine with Dwell Response — V_0 = %d m/s', v), 'FontSize', 12, 'FontWeight', 'bold'); 
    ylabel('Steering Angle (deg)', 'FontWeight', 'bold'); 
    legend('Location','best');
    
    subplot(3,1,2); 
    ylabel('Yaw Rate (deg/s)', 'FontWeight', 'bold');
    
    % Trick to display "Actual vs Reference" in the middle plot legend
    plot(NaN, NaN, 'k-', 'LineWidth', 1.5, 'DisplayName', 'Actual');
    plot(NaN, NaN, 'k--', 'LineWidth', 1.2, 'DisplayName', 'Reference (DYC)');
    legend('Location', 'best');
    
    subplot(3,1,3); 
    ylabel('V_x (m/s)', 'FontWeight', 'bold'); 
    xlabel('Time (s)', 'FontWeight', 'bold');
    
    % Force clear mode (white background, black axes) for documentation
    for ax_idx = 1:3
        ax = subplot(3,1,ax_idx);
        ax.Color = 'w'; ax.XColor = 'k'; ax.YColor = 'k'; ax.GridColor = 'k';
    end
end

disp('Tests completed successfully!');