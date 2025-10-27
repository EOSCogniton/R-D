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

Kp = 300;
Ki = 50;

q = 0.02;
epsilon = 2.5;
e_max = 0.05;

% simulation startup
Tsim = 4;
out = sim("simu_complete.slx");

%%
% data analysis
run trace_trajectoire.m
