clear, clc

load donnees_interpolees_SA.mat
load donnees_interpolees_SL.mat

run main_data_vehicle.m
run main_phi.m

% simulation setup
Frr = 0;  % comment out if friction shall be applied
TV = 0;     % torque vectoring Mz correction on(1)/off(0)
v0 = 10;    % initial speed (m/s)
delta0 = 10; % initial steering angle
deltaF = -10; % final steering angle
t_sw = 5;   % moment of time when delta0 changes to deltaF
Tr = 0.2; % toruqe request on pedal (from 0 to 1)

gamma0 = 0;%2.5; % this is the initial value of adapted parameter gamma
e_max = 0.05; % the saturation function is defined as s/e_max for |s|<e_max

% adaptation parameters
alpha_SMC = 1000;    
beta_SMC = 0.001; 
% 1/(alpha*beta) = gamma deterioration time constant
% 1/beta = gamma gain from input
% for beta = 0 this system is an integral with gain equal to alpha
% for alpha = 0 the adaptation is deactivated

% model accuracy
acc = 0.9;
% the feedforward (equivalent) control is multiplied by 
% this value to simulate system identification error 

% simulation startup
Tsim = 10;
out = sim("simu_complete_ASMC.slx");

%%
% data analysis
run trace_trajectoire.m
