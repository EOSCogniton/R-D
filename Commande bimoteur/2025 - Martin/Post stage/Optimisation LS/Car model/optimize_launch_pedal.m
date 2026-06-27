%% optimize_launch_pedal.m
% Optimisation du profil de pedale d'accelerateur u(t) in [0,1] pour
% minimiser le temps de franchissement de 75 m sur main_vehicle_v2
% (avec modele powertrain/VCU entre la pedale et le couple aux roues).
%
% IMPORTANT : lance d'abord test_single_sim.m pour valider le cablage
% et la gestion d'erreur avant de lancer ceci.

clear; clc; close all;
main_data_vehicle
%% Parametres generaux
modelName  = 'main_vehicle_v2';
simTime    = 5;         % s -- doit correspondre au StopTime du modele
dt         = 0.001;      % s -- resolution du signal de commande injecte
targetDist = 75;         % m
signalName = 'PedalCmd'; % <-- A VERIFIER : nom de variable du bloc From Workspace
uMin = 0;
uMax = 1;

load_system(modelName);


%% Parametrisation du profil de pedale
% params = [u0, upeak, tau_rise, t1, ufloor, k]
%   u0, upeak, ufloor in [0, 1]      (bornes physiques de la pedale)
%   tau_rise in [0.01, 1]            (constante de temps de montee, s)
%   t1       in [0.05, 3]            (instant de transition, s)
%   k        in [0.01, 5]            (taux de decroissance, 1/s)
%
% NOTE : le powertrain/VCU ajoute probablement sa propre dynamique
% (filtrage, cartographie couple/pedale, limiteur de pente). Si le
% comportement optimal pousse tau_rise ou t1 contre leurs bornes,
% elargis-les -- ca indique que le VCU a une dynamique plus lente/rapide
% que prevu ici.

lb = zeros(1,41);
ub = ones(1,41);

% Point de depart : montee rapide vers une pedale haute, puis leger relachement
x0 = 1/2*ones(1,41);

%% Fonction cout
costFcn = @(p) costFunction_launch(p, modelName, simTime, dt, targetDist, signalName, uMin, uMax);

%% Optimisation -- patternsearch (robuste au bruit numerique ET aux
%  echecs de simulation, geres en amont par simulateControlProfile.m)
options = optimoptions('patternsearch', ...
    'Display', 'iter', ...
    'MaxFunctionEvaluations', 10000, ...
    'UseCompletePoll', true, ...
    'MeshTolerance', 1e-4, ...
    'UseParallel', false);

fprintf('Demarrage de l''optimisation patternsearch...\n');
[xopt, Jopt] = patternsearch(costFcn, x0, [], [], [], [], lb, ub, [], options);

% fprintf('\n=== Resultat ===\n');
% fprintf('Temps optimal pour 75 m : %.4f s\n', Jopt);
% fprintf('Parametres optimaux (pedale) :\n');
% fprintf('  u1       = %.3f\n', xopt(1));
% fprintf('  u2    = %.3f\n', xopt(2));
% fprintf('  u3 = %.3f s\n', xopt(3));
% fprintf('  u4       = %.3f s\n', xopt(4));
% fprintf('  u5   = %.3f\n', xopt(5));
% fprintf('  u6        = %.3f 1/s\n', xopt(6));
% fprintf('  u7    = %.3f\n', xopt(7));
% fprintf('  u8 = %.3f s\n', xopt(8));
% fprintf('  u9       = %.3f s\n', xopt(9));
% fprintf('  u10   = %.3f\n', xopt(10));
% fprintf('  u11       = %.3f 1/s\n', xopt(11));

%% Validation et visualisation du profil optimal
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

%% Sauvegarde des resultats
save('optimal_launch_pedal_result.mat', 'xopt', 'Jopt', 't_vec', 'u_vec', 'crossTimeOpt');
fprintf('\nResultats sauvegardes dans optimal_launch_pedal_result.mat\n');
