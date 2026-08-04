s = 96;
p = 1;

Q = p * 6.6491;
initialSOC = 1;

Parameters = readtable("Parameters.csv");
OCV = readtable("OCV_LUT.csv");

SOCPoints = Parameters.SOCBP;
polyR0 = (s/p)*Parameters.R0;
polyR1 = (s/p)*Parameters.R1;
polyR2= (s/p)*Parameters.R2;
polyTau1 = Parameters.Tau1;
polyTau2 = Parameters.Tau2;
polyC1 = (p/s)*Parameters.C1;
polyC2 = (p/s)*Parameters.C2;

OCVLUT = s * OCV.OCV;
SOCLUT = OCV.SOC;


data = readtable('dados_bateria_completo.csv');
t = data.Tempo_s;
start_test = find(t == 3198.9);
end_test = 1649340;
t = t(start_test:end_test);
t = t - t(1);
I= data.Corrente_A;
I = -I(start_test:end_test)*4;
V = data.Tensao_V;
V = V(start_test:end_test);
SimTime = max(t);
