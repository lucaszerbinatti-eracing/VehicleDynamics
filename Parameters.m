% Parameter file for the FSE models
% Initialize parameters automatically when the model gets loaded:

i_Diff = 11.72;                   % mechanical transmission
    
TC_On = 1;                    % enable traction control
DYC_On = 1;                   % enable DYC
TVlong_On = 0;                % enable torque vectoring

Power = 80000;

Ts = 0.02;
Ts_fast = 0.02;
Ts_slow = 0.05;

%% ------------------------------
% Block Car Parameters
% ------------------------------
% Dados ambiente
p_ar = 1.202; % air density (equal to 1.202 kg/m³ for dry air at 20 °C and 101.325 kPa)
V_vento = 0; % m/s - Velocidade do vento
g = 9.8; % gravidade

% Dimensões do carro
Izz = 150; %kgm^2 --> Alterei pq nas teses com carros de formula varia entre 120 e 180
h = 0.265; %m
l = 1.59; %m
lf = 0.873;
lr = 0.717;
tf = 1.20; %m
tr = 1.15; %m
tf_half = 0.61; %m
tr_half = 0.60; %m
Af = 0.532;

% Pesos carro balança
m = 300; %kg
W = m*g;
FzF_0 = W*lr/l;
FzR_0 = W*lf/l;

% Características suspa & aero
Gr = 11.72;
Cd = 1.197;
Cl = 1.951;

% Dados roda/pneu
R = 0.228;
Re = 0.200;
SRmin = 0.12;
SRmax = 0.20;
Gr = 11.72;
mi = 2; % road tire friction coeficient
Tmax_motor = 25; %Nm
Tmin_motor = 0; %Nm

% Dados painel
K_Stability = 2; % 1 = understeer, 2 = neutral, 3 = oversteer
K_90_understeer = 0.0016;
K_70_understeer = 0.002644897959;
K_60_understeer = 0.0036000;
K_50_understeer = 0.0051840;
K_40_understeer = 0.0081000;
K_oversteer = -0.001;
StabilityMode = 2;

% Gain scheduling
Vx_gs = [5 10 15 20 25 30];
b = [1 1 1 1 1 1 1];

%%Agora vai

Vx_axis = [5, 10, 15, 20, 25, 30, 35];
Kp_data = [2877.5702, 2303.9999, 1972.0835, 1556.8775, 1258.2451, 1022.7085, 982.7861, ]*5; % Ganho Proporcional (P)
Ki_data = [283117.9493, 114831.615, 51596.0519, 30556.5344, 17525.221, 11773.8301, 10567.5001]*0.008; % Ganho Integral (I)
Kd_data = [0, 0, 39.3896, 34.6743, 34.4127, 38.4869, 31.1726]*1; % Ganho Derivativo (D)
N_data  = [100, 100, 13.0791, 10.4654, 7.7942, 6.1581, 6.2492]; % Coeficiente do Filtro (N)

%%----------------
P_v = [26635.7064 21634.6935 7285.2525 5680.3598 4865.9167, 3697.5585]*10e-1;
I_v = [6531985.9289 2899509.015 589299.8624 354399.2358 234977.839 136765.2955]*10e-3;

P_teste = [982.0966 6665.4153 8532.9765 9160.6099 9835.4319 10243.6396];
I_teste = [1284821.5948 874015.7951 730929.315 702913.055 664249.3661 542870.8806]*10e-100;



K_t =Ki_data./Kp_data;

Vx = [0, 12.5, 23.6, 30, 35];
K_variavel = [-0.001, 0, 0.0008, 0.0012, 0.0015];

% Cornering Stiffiness
Fz_cs = [222.41 444.82 667.23 889.64 1112.05]; % N
Cs = [19075.58 25992.80 31792.64 35898.02 39044.37]; % N/rad

% Limites Controle PI
pedal = [0 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100];
Mz_maxF = [0 66.3 132.6 198.9 265.2 330.23 396.52 462.83 529.112 595.42 661.73 728.03 794.33 860.62 926.92 993.23 1058.25 1124.55 1190.85 1257.15 1323.45 1389.75 1456.05 1522.35 1588.65 1654.95];
Mz_minF = [0 -66.3 -132.6 -198.9 -265.2 -330.23 -396.52 -462.83 -529.112 -595.42 -661.73 -728.03 -794.33 -860.62 -926.92 -993.23 -1058.25 -1124.55 -1190.85 -1257.15 -1323.45 -1389.75 -1456.05 -1522.35 -1588.65 -1654.95];
