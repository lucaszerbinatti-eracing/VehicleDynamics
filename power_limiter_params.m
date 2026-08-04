% POWER_LIMITER_PARAMS  Calibração default do bloco power_limiter (VCU Ecotron)
% Rode este script antes de simular o modelo Simulink que contém o bloco.
% No target, estes valores viram calibratable parameters da VCU.
%
% Origem dos valores: PLANO_Controle_Potencia_VCU.md + extração do Torque.mat
% (P_max real = 54,0 kW mecânico, pico de P = T·ω instantâneo; p95 = 36,6 kW).

% ---- Plano de SOC / orçamento de energia ----
SOC_start   = 1.0;        % [-]  SOC no início da prova
SOC_reserva = 0.10;       % [-]  reserva no fim (TODO §10: 5% vs 10%)
D_total     = 22000;      % [m]  distância do endurance
E_total_J   = 8.98e6;     % [J]  energia total do pack (~2,49 kWh)
eta         = 0.91;       % [-]  eficiência motor+inversor (P_mec = eta*P_elec)

% ---- Saturações do teto de potência (mecânica total) ----
P_max = 54e3;             % [W]  pico real extraído do Torque.mat (P = T·ω)
P_min = 5e3;              % [W]  piso de dirigibilidade (TODO §10: validar em pista)

% ---- Dinâmica do teto ----
dPdt_max = 25e3;          % [W/s] rate limit do teto (TODO §10: conforto do piloto)
Ts       = 0.01;          % [s]   passo do bloco na VCU (TODO §10: confirmar taxa)

% ---- Ganhos do PI (chutes iniciais — sintonizar, §10) ----
% e é adimensional (fração de SOC): e = 0.01 (1% de desvio) com Kp = 2e5
% corrige o teto em 2 kW. Ki fecha o desvio em regime (~ Kp/60 s).
Kp = 2e5;                 % [W por unidade de SOC]
Ki = 3e3;                 % [W/(unidade de SOC · s)]

% ---- Fallback (perda de CAN / sinal inválido) ----
% Teto conservador de torque total quando as entradas são inválidas.
% ~20 Nm total ≈ 5 Nm/motor — mantém dirigibilidade sem drenar o pack.
T_fallback = 20;          % [Nm]

disp('power_limiter_params: parâmetros carregados no workspace.')
