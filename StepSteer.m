%% Step Steer Test (Velocity-Based Simulation and Plotting)
clear; clc; close all;


modelo = 'PlanarModelandControl';
load_system(modelo);

%% 1. PARAMETERS
velocities  = [5, 10, 15];   % [m/s]
amplitudes  = [15, 30, 45];  % [deg] Steering wheel angle
total_time  = 4.6;           % 0.5s (straight) + 0.1s (step) + 4.0s (hold)

% Command time vector (named t_cmd to avoid conflicts with Simulink's internal 't')
t_cmd = (0:0.01:total_time)';

% Fixed commands (constant throughout the loop)
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
    
    % Create a new figure for the current velocity with 3 subplots
    fig = figure('Name', sprintf('Step Steer - V = %d m/s', v), 'Color', 'w', ...
                 'Position', [100 100 900 700]);
    
    fprintf('\n--- Testing V0 = %d m/s ---\n', v);
    
    for i = 1:length(amplitudes)
        a = amplitudes(i);
        current_color = plot_colors(i, :);
        
        % Generate steering signal (starts at 0.5s, 0.1s ramp up)
        steer = min(max((t_cmd - 0.5) / 0.1, 0), 1) * a;
        assignin('base', 'Steer_Cmd', [t_cmd, steer]);
        
        % Run simulation
        out = sim(modelo, 'StopTime', num2str(total_time));
        
        % Extract data (Format: Structure with Time)
        t_sim   = out.v_yaw.time; 
        yaw     = rad2deg(out.v_yaw.signals.values);
        yaw_ref = rad2deg(out.Yaw_des.signals.values); 
        ay      = out.Ay_out.signals.values / 9.81; % Convert to [G]
        
        % Calculate basic metrics (steady-state evaluated over the last 1.0 second)
        idx_ss = t_sim > (total_time - 1.0);
        yaw_ss = mean(yaw(idx_ss));
        yaw_ref_ss = mean(yaw_ref(idx_ss));
        
        peak_yaw = max(abs(yaw(t_sim >= 0.6))); % Peak after the step input
        overshoot = max(0, (peak_yaw / abs(yaw_ref_ss) - 1) * 100);
        
        % Console output in Technical English
        fprintf('Steering: %d deg | Yaw Gain: %.3f (deg/s)/deg | Overshoot (Ref): %.1f%%\n', ...
                a, yaw_ss/a, overshoot);
        
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
        
        % 3. Lateral Acceleration (Ay)
        subplot(3,1,3); hold on; grid on;
        plot(t_sim, ay, 'Color', current_color, 'LineWidth', 1.5, 'HandleVisibility', 'off');
    end
    
    % --- FORMATTING THE CURRENT VELOCITY FIGURE ---
    figure(fig);
    
    subplot(3,1,1); 
    title(sprintf('Step Steer Response — V_0 = %d m/s', v), 'FontSize', 12, 'FontWeight', 'bold'); 
    ylabel('Steering Angle (deg)', 'FontWeight', 'bold'); 
    legend('Location', 'best');
    
    subplot(3,1,2); 
    ylabel('Yaw Rate (deg/s)', 'FontWeight', 'bold');
    
    % Trick to display "Actual vs Reference" in the middle plot legend
    plot(NaN, NaN, 'k-', 'LineWidth', 1.5, 'DisplayName', 'Actual');
    plot(NaN, NaN, 'k--', 'LineWidth', 1.2, 'DisplayName', 'Reference (DYC)');
    legend('Location', 'best');
    
    subplot(3,1,3); 
    ylabel('A_y (G)', 'FontWeight', 'bold'); 
    xlabel('Time (s)', 'FontWeight', 'bold');
    
    % Force clear mode (white background, black axes) for documentation
    for ax_idx = 1:3
        ax = subplot(3,1,ax_idx);
        ax.Color = 'w'; ax.XColor = 'k'; ax.YColor = 'k'; ax.GridColor = 'k';
    end
end

disp('Tests completed successfully!');