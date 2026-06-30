%% refine_launch_pedal.m
% Version minimale qui fonctionnait : patternsearch seul, point de depart
% = xBest recupere du GA precedent. Pas de Rebuild, pas de GA -- juste
% l'algorithme de raffinement de base, borne en temps par securite.

clear; clc; close all;
main_data_vehicle

%% Parametres generaux
modelName  = 'main_vehicle_v2';
simTime    = 5;
dt         = 0.001;
targetDist = 75;
signalName = 'PedalCmd';
uMin = 0;
uMax = 1;

load_system(modelName);
load('xOptCorrected.mat')

nVars = 11;
lb = zeros(1, nVars);
ub = ones(1, nVars);
x0 = xOptCorrected;

%% Fonction cout
costFcn = @(p) costFunction_launch(p, modelName, simTime, dt, targetDist, signalName, uMin, uMax);

fprintf('Cout au point de depart (xBest) : J = %.4f\n', costFcn(x0));

%% Optimisation -- patternsearch seul, borne en temps
options = optimoptions('patternsearch', ...
    'Display',                'iter', ...
    'MaxFunctionEvaluations', 300, ...
    'MaxTime',                3600, ...
    'UseCompletePoll',        true, ...
    'MeshTolerance',          1e-4, ...
    'UseParallel',            false);

fprintf('Demarrage du raffinement patternsearch...\n');
tic;
[xopt, Jopt] = patternsearch(costFcn, x0, [], [], [], [], lb, ub, [], options);
fprintf('Temps ecoule : %.1f s\n', toc);

fprintf('\n=== Resultat ===\n');
fprintf('Temps optimal pour 75 m : %.4f s\n', Jopt);
disp(xopt);

%% Validation et visualisation
[crossTimeOpt, ~, xCarOpt] = simulateControlProfile(xopt, modelName, simTime, dt, targetDist, signalName, uMin, uMax);
[t_vec, u_vec] = buildControlProfile2(xopt, simTime, dt, uMin, uMax);

if isnan(crossTimeOpt)
    error('Le profil optimal renvoye echoue en simulation -- verifie les bornes/parametrisation.');
end

tWindow = min(simTime, crossTimeOpt*1.5);

figure;
subplot(2,1,1);
plot(t_vec, u_vec, 'LineWidth', 1.5);
xlabel('Temps (s)'); ylabel('Commande pedale (0-1)');
ylim([0, 1.05]);
xlim([0, tWindow]);
grid on; title('Profil de pedale optimal u(t)');

subplot(2,1,2);
plot(xCarOpt.Time, xCarOpt.Data, 'LineWidth', 1.5);
hold on;
yline(targetDist, '--r', '75 m');
xline(crossTimeOpt, '--k', sprintf('%.3f s', crossTimeOpt));
xlabel('Temps (s)'); ylabel('xCar (m)');
xlim([0, tWindow]);
grid on; title('Position longitudinale xCar(t)');

%% Sauvegarde
save('optimal_launch_pedal_refined.mat', 'xopt', 'Jopt', 't_vec', 'u_vec', 'crossTimeOpt');
fprintf('\nResultats sauvegardes dans optimal_launch_pedal_refined.mat\n');