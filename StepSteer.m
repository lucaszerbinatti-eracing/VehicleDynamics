%% Teste Step Steer (Simplificado com Gráficos por Velocidade)
clear; clc; close all;

modelo = 'PlanarModelandControl';
load_system(modelo);

%% 1. PARÂMETROS
velocidades = [5];   % [m/s]
amplitudes  = [30];  % [deg] de volante
tempo_total = 4.6;           % 0.5s (reto) + 0.1s (degrau) + 4.0s (hold)

% Vetor de tempo de comando
t = (0:0.01:tempo_total)';

% Comandos fixos (não mudam no loop)
assignin('base', 'Accel_Cmd', [t, zeros(size(t))]);
assignin('base', 'Brake_Cmd', [t, zeros(size(t))]);
assignin('base', 'Flag_CruiseControl', 1);
assignin('base', 'Controles_Ativos', 0);
assignin('base', 'GG_mode', 0);
cores = lines(length(amplitudes)); % Paleta de cores para as amplitudes

% --- VARIAVEIS PARA O GRÁFICO DO HANDBOOK (UNDERSTEER) ---
vel_kmh = velocidades * 3.6; % Convertendo para km/h para o gráfico
Ku_array = zeros(size(velocidades)); % Vetor para guardar o Coef. Understeer
amp_referencia = 30; % Usaremos o degrau de 30 graus como referência para o Ku

%% 2. LOOP DE SIMULAÇÃO
for v_idx = 1:length(velocidades)
    v = velocidades(v_idx);
    
    % Atualiza velocidade inicial e referência
    assignin('base', 'Vx_Ref', v);
    assignin('base', 'Vx_init', v);
    
    % Cria uma nova figura para esta velocidade com 3 subplots
    fig = figure('Name', sprintf('Step Steer - V=%d m/s', v), 'Color', 'w', ...
                 'Position', [100 100 900 700]);
    
    fprintf('\n--- Testando V0 = %d m/s ---\n', v);
    
    for i = 1:length(amplitudes)
        a = amplitudes(i);
        cor = cores(i, :);
        
        % Cria o sinal de volante (começa em 0.5s, sobe em 0.1s)
        steer = min(max((t - 0.5) / 0.1, 0), 1) * a;
        assignin('base', 'Steer_Cmd', [t, steer]);
        
        % Simula (sem o ShowProgress)
        out = sim(modelo, 'StopTime', num2str(tempo_total), 'SimulationMode', 'normal');
        
        % Extrai os dados (Formato: Structure with Time)
        t_sim   = out.v_yaw.time; 
        yaw     = rad2deg(out.v_yaw.signals.values);
        yaw_ref = rad2deg(out.Yaw_des.signals.values); 
        ay      = out.Ay_out.signals.values / 9.81; % Ay em [G]
        
        % Calcula métricas simples (último 1 segundo para regime permanente)
        idx_ss = t_sim > (tempo_total - 1.0);
        yaw_ss = mean(yaw(idx_ss));
        yaw_ref_ss = mean(yaw_ref(idx_ss));
        ay_ss = mean(ay(idx_ss)); % Aceleração lateral em regime permanente
        
        pico = max(abs(yaw(t_sim >= 0.6))); % Pico após o degrau
        overshoot = max(0, (pico / abs(yaw_ref_ss) - 1) * 100);
        
        fprintf('Volante: %d deg | Ganho: %.3f (deg/s)/deg | Overshoot (Ref): %.1f%%\n', ...
                a, yaw_ss/a, overshoot);
            
        % --- COLETANDO DADO PARA O HANDBOOK ---
        % Se for o nosso degrau de referência (30 deg), guardamos o gradiente
        if a == amp_referencia
            % Gradiente empírico: Quanto de volante (deg) custa gerar 1G de Ay
            Ku_array(v_idx) = a / ay_ss; 
        end
        
        % --- PLOTAGENS NESTA FIGURA ---
        figure(fig);
        nome_legenda = sprintf('%d deg', a);
        
        % 1. Volante
        subplot(3,1,1); hold on; grid on;
        plot(t, steer, 'Color', cor, 'LineWidth', 1.5, 'DisplayName', nome_legenda);
        
        % 2. Yaw Rate (Contínuo = Real, Tracejado = Referência)
        subplot(3,1,2); hold on; grid on;
        plot(t_sim, yaw, 'Color', cor, 'LineWidth', 1.5, 'HandleVisibility', 'off');
        plot(t_sim, yaw_ref, '--', 'Color', cor, 'LineWidth', 1.2, 'HandleVisibility', 'off');
        
        % 3. Aceleração Lateral (Ay)
        subplot(3,1,3); hold on; grid on;
        plot(t_sim, ay, 'Color', cor, 'LineWidth', 1.5, 'HandleVisibility', 'off');
    end
    
    % --- FORMATANDO A FIGURA DA VELOCIDADE ATUAL ---
    figure(fig);
    
    subplot(3,1,1); 
    title(sprintf('Step Steer  V0 = %d m/s', v)); 
    ylabel('Volante (deg)'); 
    legend('Location','best');
    
    subplot(3,1,2); 
    ylabel('Yaw Rate (deg/s)');
    plot(NaN, NaN, 'k-', 'LineWidth', 1.5, 'DisplayName', 'Real');
    plot(NaN, NaN, 'k--', 'LineWidth', 1.2, 'DisplayName', 'Referência (DYC)');
    legend('Location', 'best');
    
    subplot(3,1,3); 
    ylabel('Ay (G)'); xlabel('Tempo (s)');
end

disp('Ensaios concluídos! Gerando gráfico para o Handbook...');

%% 3. GERAÇÃO DO GRÁFICO PARA O LATEX (Understeer Gradient)
fig_ku = figure('Name', 'Understeer Gradient', 'Color', 'w');
plot(vel_kmh, Ku_array, '-o', 'LineWidth', 2, 'MarkerFaceColor', 'b', 'MarkerSize', 8);
grid on;
title('Gradiente de Esterço (Understeer) vs Velocidade');
xlabel('Velocidade (km/h)');
ylabel('Graus de Volante por G (deg/G)');

% Exporta automaticamente na mesma pasta
exportgraphics(fig_ku, 'Understeer_Gradient.eps', 'ContentType', 'vector');
disp('Arquivo "Understeer_Gradient.eps" gerado com sucesso!');