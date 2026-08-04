%% Script de Simulação - Autocross (Driver Automático / Stanley)
clear; clc; close all;

modelo = 'PlanarModelandControl';
load_system(modelo); % Carrega o modelo na memória para poder usar o set_param


%% 2. CARREGAMENTO DO MAPA E TRAJETÓRIA
load('Trajetoria_Stanley_autocross.mat');
Theta_deg = rad2deg(Pose_Timeseries(:, 4));
Mapa_Pista = [Pose_Timeseries(:, 2), Pose_Timeseries(:, 3), Theta_deg];
Mapa_V_Estatico = double(Ref_V_Estatico);
Mapa_V_Lancado  = double(Ref_V_Lancado);

%% 3. VARIÁVEIS NASA / ESTADO DO CARRO
GG_mode = 0;
Controles_Ativos = 1; % Mantém Torque Vectoring e TC ligados para a prova
Vx_init = 0;          % Carro larga parado
Vx_Ref = 0;

% O Autocross tem controle próprio de pedal, então o Cruise Control deve ficar OFF.
% (Assumindo que o Driver1 gere os comandos de aceleração e freio baseados no Mapa_V)
Flag_CruiseControl = 0; 

%% 4. VARIÁVEIS "DUMMY" (Para blindar o InitFcn)
% Como o Driver do Autocross substitui os comandos manuais pelo controle autônomo,
% criamos esses vetores zerados apenas para o Simulink não dar erro de porta vazia.
t_dummy = [0; 1000];
Accel_Cmd = [t_dummy, [0; 0]];
Brake_Cmd = [t_dummy, [0; 0]];
Steer_Cmd = [t_dummy, [0; 0]];

%% 5. EXECUÇÃO DA SIMULAÇÃO
% Define quanto tempo o carro tem para completar a pista (Ajuste se necessário)
tempo_max_autocross = 120; % 120 segundos

disp('Iniciando simulação do Autocross (isso pode levar vários minutos)...');
out = sim(modelo, 'StopTime', num2str(tempo_max_autocross));
disp('Simulação do Autocross concluída com sucesso!');

% Aqui você pode adicionar códigos de plot (ex: plotar X e Y para ver a volta na pista)
% plot(out.Pos_X.Data, out.Pos_Y.Data);