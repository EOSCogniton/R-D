%% test_single_sim.m
% A LANCER EN PREMIER, avant optimize_launch_pedal.m.
%
% Teste maintenant la commande de pedale (0 a 1) injectee dans le modele
% powertrain/VCU, et verifie :
%   1) que le bloc From Workspace accepte le format construit ici
%   2) que xCar est correctement recupere depuis simOut
%   3) que la gestion d'erreur (modele pneu qui diverge) fonctionne bien
%      sans planter MATLAB

clear; clc;
main_data_vehicle

modelName  = 'main_vehicle_v2';
simTime    = 10;        % s, doit correspondre au StopTime du modele
dt         = 0.001;     % s, resolution du signal de commande
targetDist = 75;        % m
signalName = 'PedalCmd'; % <-- A VERIFIER : nom exact de la variable lue
                         %     par ton bloc From Workspace cote VCU
uMin = 0;
uMax = 1;

load_system(modelName);

%% Test 1 : pedale moderee et constante (0.5), devrait rester physique
% params = [u0, upeak, tau_rise, t1, ufloor, k]
paramsModere = [0.5, 0.5, 0.01, 0.5, 0.5, 0.01];

[crossTime1, ~, xCar1] = simulateControlProfile(paramsModere, modelName, ...
    simTime, dt, targetDist, signalName, uMin, uMax);

if isnan(crossTime1)
    fprintf('Test 1 (pedale=0.5) : 75 m jamais atteint ou simulation echouee.\n');
else
    fprintf('Test 1 (pedale=0.5 constante) : 75 m atteint en %.3f s\n', crossTime1);
end

figure;
plot(xCar1.Time, xCar1.Data, 'LineWidth', 1.5);
xlabel('Temps (s)'); ylabel('xCar (m)');
yline(targetDist, '--r', '75 m');
grid on;
title('Test 1 : pedale constante 0.5 (devrait etre physique)');

%% Test 2 : pedale a fond (1.0) -- pour VERIFIER que la gestion d'erreur
% fonctionne si ca depasse les limites du modele pneu/powertrain.
% Si une erreur Simulink apparait dans la console mais que MATLAB NE
% PLANTE PAS et renvoie crossTime = NaN, c'est le comportement attendu.
paramsAgressif = [1.0, 1.0, 0.01, 0.5, 1.0, 0.01];

[crossTime2, ~, ~] = simulateControlProfile(paramsAgressif, modelName, ...
    simTime, dt, targetDist, signalName, uMin, uMax);

if isnan(crossTime2)
    fprintf('Test 2 (pedale=1.0) : NaN renvoye comme attendu (sim echouee ou non-physique).\n');
else
    fprintf('Test 2 (pedale=1.0 constante) : 75 m atteint en %.3f s (semble physique, OK).\n', crossTime2);
end
