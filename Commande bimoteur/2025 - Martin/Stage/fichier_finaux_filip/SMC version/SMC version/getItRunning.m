clear, clc

load donnees_interpolees_SA.mat
load donnees_interpolees_SL.mat

run main_data_vehicle.m
run main_phi.m

% simulation setup
% Frr = 0;  % comment out if friction shall be applied
TV = 1;     % torque vectoring Mz correction on(1)/off(0)
v0 = 10;    % initial speed (m/s)
delta0 = 7; % initial steering angle
deltaF = 0; % final steering angle
t_sw = 2;   % moment of time when delta0 changes to deltaF
Tr = 0.195; % toruqe request on pedal (from 0 to 1)

q = 0.6;
epsilon = 2.5;
e_max = 0.05; % 1/e_max is a value of gain in saturation switching function

% simulation startup
Tsim = 4;
out = sim("simu_complete_SMC.slx");

%%
% data analysis
run trace_trajectoire.m
