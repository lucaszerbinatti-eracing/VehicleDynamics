%% ========================================================================
%  TESTE DE VALIDAÇÃO — CURVA G-G AUTOMATIZADA PARA MÚLTIPLAS VELOCIDADES
%  Estratégia: nuvem transiente + fronteira radial (Loop de automação)
% =========================================================================
clear; clc; close all;
%% 1. CONFIGURAÇÃO PRINCIPAL
NOME_MODELO = 'PlanarModelandControl';
% ---> AQUI VOCÊ DEFINE QUAIS VELOCIDADES QUER SIMULAR <---
Vetor_V0 = [5, 10, 15, 20]; % m/s
T_sim       = 6;         % s
TOL_V       = 1;         % m/s — tolerância para pertencer à fatia V0
Controles_Ativos = 1;
LIMITE_BETA        = deg2rad(10);
LIMITE_KAPPA_FREIO = -0.25;
LIMITE_KAPPA_ACCEL =  0.25;
Angulos_Steer   = [10, 20, 35, 50, 70, 90];   % graus
Throttle_Levels = [0.4, 0.7, 1.0];            % preenche interior
n_pts   = T_sim * 100;
t_array = linspace(0, T_sim, n_pts)';
acc_suave = min(1, t_array/2);
brk_suave = max(0, min(1, (t_array-0.5)/1.5));
N_SETORES = 24; % 15° cada
edges = linspace(-pi, pi, N_SETORES+1);
g = 9.81;
% Estrutura para salvar os dados finais de todas as velocidades
Resultados_GG = struct('V0', {}, 'b_ax', {}, 'b_ay', {});
% Carrega o modelo uma vez para economizar tempo
load_system(NOME_MODELO);
figure('Name', 'Diagramas G-G Consolidados', 'Color','w');
hold on; grid on; axis equal;
cores = lines(length(Vetor_V0)); % Paleta de cores para o gráfico final
%% ---> INÍCIO DO LAÇO DE AUTOMAÇÃO (O TRABALHO BRAÇAL) <---
for idx_v = 1:length(Vetor_V0)
    V0 = Vetor_V0(idx_v);
    
    fprintf('\n======================================================\n');
    fprintf('=== INICIANDO SIMULAÇÕES PARA V0 = %d m/s ===\n', V0);
    fprintf('======================================================\n');
    
    % LIMPEZA VITAL: Zera as matrizes para não misturar dados com o V0 anterior
    AX_all = []; AY_all = []; VX_all = [];
    
    %% 2. Biblioteca de Manobras (Adaptada dinamicamente para V0)
    
    % --- 1. Aceleração pura ---
    acc_pura = min(1, t_array / 0.2);
    v_ini_acc = 0.85 * V0; % Antes era 8.5 para V0=10
    [ax,ay,vx] = ExecutaManobra_v2(NOME_MODELO, v_ini_acc, V0, T_sim, t_array, ...
        zeros(n_pts,1), acc_pura, zeros(n_pts,1), 0, ...
        LIMITE_BETA, LIMITE_KAPPA_FREIO, LIMITE_KAPPA_ACCEL);
    AX_all=[AX_all;ax]; AY_all=[AY_all;ay]; VX_all=[VX_all;vx];
    
    % --- 2. Frenagem pura ---
    brk_pura = max(0, min(1, (t_array - 0.2) / 0.5));
    v_ini_brk = 1.40 * V0; % Antes era 14 para V0=10
    [ax,ay,vx] = ExecutaManobra_v2(NOME_MODELO, v_ini_brk, V0, T_sim, t_array, ...
        zeros(n_pts,1), zeros(n_pts,1), brk_pura, 0, ...
        LIMITE_BETA, LIMITE_KAPPA_FREIO, LIMITE_KAPPA_ACCEL);
    AX_all=[AX_all;ax]; AY_all=[AY_all;ay]; VX_all=[VX_all;vx];
    
    % --- 3. Curva pura (cruise control mantém V0) ---
    steer_curva = linspace(0,100,n_pts)';
    [ax,ay,vx] = ExecutaManobra_v2(NOME_MODELO, V0, V0, T_sim, t_array, ...
        steer_curva, zeros(n_pts,1), zeros(n_pts,1), 1, ...
        LIMITE_BETA, LIMITE_KAPPA_FREIO, LIMITE_KAPPA_ACCEL);
    AX_all=[AX_all; ax; ax]; AY_all=[AY_all; ay; -ay]; VX_all=[VX_all; vx; vx];
    
    % --- 4. Aceleração em curva (Grade Combinada) ---
    for delta = Angulos_Steer
        for th = Throttle_Levels
            steer_acc = delta * min(1, t_array / 0.5);
            acc_comb  = th * min(1, t_array / 0.5);
            
            [ax,ay,vx] = ExecutaManobra_v2(NOME_MODELO, v_ini_acc, V0, T_sim, t_array, ...
                steer_acc, acc_comb, zeros(n_pts,1), 0, ...
                LIMITE_BETA, LIMITE_KAPPA_FREIO, LIMITE_KAPPA_ACCEL);
            AX_all=[AX_all; ax; ax]; AY_all=[AY_all; ay; -ay]; VX_all=[VX_all; vx; vx];
        end
    end
    
    % --- 5. Frenagem em curva (Trail Braking Multi-Velocidade) ---
    Velocidades_Brk = [1.05, 1.20, 1.40] * V0; % Antes era [10.5, 12, 14]
    for delta = Angulos_Steer
        for v_ini_brk_curva = Velocidades_Brk
            steer_brk = delta * min(1, t_array / 0.2);
            brk_comb  = max(0, min(1, (t_array - 0.2) / 0.2));
            
            [ax,ay,vx] = ExecutaManobra_v2(NOME_MODELO, v_ini_brk_curva, V0, T_sim, t_array, ...
                steer_brk, zeros(n_pts,1), brk_comb, 0, ...
                LIMITE_BETA, LIMITE_KAPPA_FREIO, LIMITE_KAPPA_ACCEL);
            AX_all=[AX_all; ax; ax]; AY_all=[AY_all; ay; -ay]; VX_all=[VX_all; vx; vx];
        end
    end
    
    %% 3. FILTRA FATIA V0 ± TOL_V
    mask_v = abs(VX_all - V0) < TOL_V;
    ax_v0 = AX_all(mask_v);
    ay_v0 = AY_all(mask_v);
    fprintf('Pontos na faixa V=%.1f±%.1f: %d\n', V0, TOL_V, sum(mask_v));
    if length(ax_v0) < 10
        warning('Poucos pontos na faixa — aumente TOL_V ou T_sim.');
    end
    
    %% 4. FRONTEIRA — MÁXIMO RADIAL POR SETOR ANGULAR
    theta_pts = atan2(ax_v0, ay_v0); % convenção: eixo X=Ay, eixo Y=Ax
    r_pts = sqrt(ax_v0.^2 + ay_v0.^2);
    boundary_ax = nan(N_SETORES,1);
    boundary_ay = nan(N_SETORES,1);
    
    for s = 1:N_SETORES
        m = theta_pts >= edges(s) & theta_pts < edges(s+1);
        if any(m)
            idxs = find(m);
            [~, idx_max] = max(r_pts(idxs));
            idx_sel = idxs(idx_max);
            boundary_ax(s) = ax_v0(idx_sel);
            boundary_ay(s) = ay_v0(idx_sel);
        end
    end
    
    valid = ~isnan(boundary_ax);
    b_ax = [boundary_ax(valid); boundary_ax(find(valid,1))];
    b_ay = [boundary_ay(valid); boundary_ay(find(valid,1))];
    
    n_vazios = sum(~valid);
    if n_vazios > 0
        fprintf('[AVISO] Para V0 = %d, %d/%d setores ficaram vazios.\n', V0, n_vazios, N_SETORES);
    end
    
    %% 5. SALVA OS DADOS E PLOTA NO GRÁFICO FINAL
    Resultados_GG(idx_v).V0 = V0;
    Resultados_GG(idx_v).b_ax = b_ax;
    Resultados_GG(idx_v).b_ay = b_ay;
    
    plot(b_ay/g, b_ax/g, 'r-o', 'LineWidth', 2, 'Color', cores(idx_v,:), ...
        'MarkerFaceColor', cores(idx_v,:), ...
        'DisplayName', sprintf('Fronteira V = %d m/s', V0));
end
%% ---> FIM DO LAÇO DE AUTOMAÇÃO <---
% Finaliza a configuração do gráfico consolidado
xline(0,'--k','HandleVisibility','off');
yline(0,'--k','HandleVisibility','off');
xlabel('A_y [g]'); ylabel('A_x [g]');
title('Diagramas G-G Consolidados — Múltiplas Velocidades');
legend('Location','best');
% Salva o struct com todos os dados no disco para você usar depois!
save('GG_Multiplas_Velocidades_Resultado.mat', 'Resultados_GG');
fprintf('\n======================================================\n');
fprintf('Sucesso! Dados salvos no arquivo "GG_Multiplas_Velocidades_Resultado.mat"\n');
fprintf('A variável "Resultados_GG" contém todos os envelopes.\n');
fprintf('======================================================\n');
%% ========================================================================
function [ax_v, ay_v, vx_v] = ExecutaManobra_v2(modelo, v_inicial, v_ref, t_sim, t_array, ...
                                                steer_vec, acc_vec, brk_vec, flag_cc, ...
                                                lim_beta, lim_k_brk, lim_k_acc)
    % SUA FUNÇÃO EXATA PERMANECE AQUI INTACTA.
    % (Código original colado para garantir funcionamento)
    ax_v = []; ay_v = []; vx_v = [];
    
    assignin('base', 'Steer_Cmd', [t_array, steer_vec]);
    assignin('base', 'Accel_Cmd', [t_array, acc_vec]);
    assignin('base', 'Brake_Cmd', [t_array, brk_vec]);
    assignin('base', 'Flag_CruiseControl', flag_cc);
    
    in = Simulink.SimulationInput(modelo);
    in = in.setVariable('Vx_Ref', v_ref);
    in = in.setVariable('Vx_init', v_inicial);
    in = in.setVariable('GG_mode', 1);
    in = in.setModelParameter('StopTime', num2str(t_sim));
    in = in.setModelParameter('FastRestart', 'off');
    
    try
        out = sim(in, 'ShowProgress','off');
        ax = extrair_sinal(out,'ax');
        ay = extrair_sinal(out,'ay');
        vx = extrair_sinal(out,'vx');
        beta = extrair_sinal(out,'Beta_out');
        k_fl = extrair_sinal(out,'Kappa_fl');
        k_fr = extrair_sinal(out,'Kappa_fr');
        k_rl = extrair_sinal(out,'Kappa_rl');
        k_rr = extrair_sinal(out,'Kappa_rr');
        
        if isempty(ax)||isempty(ay)||isempty(vx), return; end
        n = length(ax);
        idx_spin=[]; if ~isempty(beta), idx_spin=find(abs(beta)>lim_beta,1,'first'); end
        idx_lockup=[]; idx_wheelspin=[];
        if ~isempty(k_fl)&&~isempty(k_fr)&&~isempty(k_rl)&&~isempty(k_rr)
            min_k = min([k_fl,k_fr,k_rl,k_rr],[],2);
            max_k = max([k_fl,k_fr,k_rl,k_rr],[],2);
            idx_lockup = find(min_k<lim_k_brk,1,'first');
            idx_wheelspin = find(max_k>lim_k_acc,1,'first');
        end
        idx_parou = find(vx<1.0,1,'first');
        candidatos = [idx_spin, idx_lockup, idx_wheelspin, idx_parou];
        idx_limite = n;
        if ~isempty(candidatos), idx_limite = min(candidatos); end
        idx_ini = min(6, idx_limite);
        ax_v = double(ax(idx_ini:idx_limite));
        ay_v = double(ay(idx_ini:idx_limite));
        vx_v = double(vx(idx_ini:idx_limite));
    catch ME
        warning('ExecutaManobra_v2 falhou: %s', ME.message);
    end
end
function v = extrair_sinal(out, nome)
    v = [];
    try
        raw = out.(nome);
        if isa(raw,'timeseries')
            v = double(raw.Data(:));
        elseif isa(raw,'Simulink.SimulationData.Dataset')
            v = double(raw.getElement(1).Values.Data(:));
        elseif isnumeric(raw)
            v = double(raw(:));
        else
            v = double(raw(:));
        end
    catch
        v = [];
    end
end
 