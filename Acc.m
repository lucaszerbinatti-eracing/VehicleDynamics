%% Teste de Aceleração (Prova de 75m)
clear; clc; close all;
modelo = 'PlanarModelandControl';
load_system(modelo);

%% 1. PARÂMETROS E COMANDOS
tempo_max_seguranca = 15; 
t = (0:0.01:tempo_max_seguranca)';
% Acelerador: vai de 0 a 1 (100%) em 1 segundo e se mantém
accel = min(t / 0.1, 1);
assignin('base', 'Accel_Cmd', [t, accel]);
assignin('base', 'Steer_Cmd', [t, zeros(size(t))]);
assignin('base', 'Brake_Cmd', [t, zeros(size(t))]);
assignin('base', 'Flag_CruiseControl', 0);
assignin('base', 'Vx_init', 0);
assignin('base', 'Vx_Ref', 0);
assignin('base', 'GG_mode', 0);

modos_tc = [0, 1];
nomes_tc = {'TC OFF (No Control)', 'TC ON (Fuzzy Active)'};
cores    = lines(2);

%% 2. PREPARAÇÃO DOS GRÁFICOS
fig = figure('Name', 'Acceleration Test 75m', 'Color', 'w', ...
             'Position', [100 100 900 600]);
fprintf('\n=== STARTING ACCELERATION TEST (75 meters) ===\n');

%% 3. LOOP DE SIMULAÇÃO (TC OFF vs TC ON)
for i = 1:length(modos_tc)
    tc_status = modos_tc(i);
    cor = cores(i, :);
    
    assignin('base', 'Controles_Ativos', tc_status);
    fprintf('Simulating: %s...\n', nomes_tc{i});
    
    out = sim(modelo, 'StopTime', num2str(tempo_max_seguranca));
    
    t_sim = out.Vx_out.time; 
    vx    = out.Vx_out.signals.values; 
    ax    = out.Ax_out.signals.values / 9.81; % In G
    
    tempo_75m = t_sim(end);
    vel_final = vx(end) * 3.6; % km/h
    max_g     = max(ax);
    
    fprintf('  -> 75m Time: %.3f s | Final Vel: %.1f km/h | Max G: %.2f G\n', ...
            tempo_75m, vel_final, max_g);
    
    % --- PLOTAGENS ---
    figure(fig);
    nome_leg = sprintf('%s (%.3f s)', nomes_tc{i}, tempo_75m);
    
    % 1. Longitudinal Acceleration (G)
    subplot(2,1,1); hold on; grid on;
    plot(t_sim, ax, 'Color', cor, 'LineWidth', 1.5, 'DisplayName', nome_leg);
    
    % 2. Longitudinal Velocity (km/h)
    subplot(2,1,2); hold on; grid on;
    plot(t_sim, vx * 3.6, 'Color', cor, 'LineWidth', 1.5, 'HandleVisibility', 'off');
end

%% 4. FORMATAÇÃO DA FIGURA
subplot(2,1,1);
title('0 - 75 Meters Acceleration Test');
ylabel('Longitudinal Acceleration (g)');
legend('Location', 'best');

subplot(2,1,2);
ylabel('Velocity (km/h)');
xlabel('Time (s)');

disp('Tests concluded!');

%% 5. SALVAR EM EPS (Como você pediu antes)
print('Acceleration_Test_75m', '-depsc', '-painters');
fprintf('\nFigure saved as "Acceleration_Test_75m.eps"\n');