%% sweep_constant_pedal.m
% Caracterise le temps de franchissement de 75 m pour differentes valeurs
% de pedale CONSTANTE. Objectif : comprendre pourquoi pedale=0.5 et
% pedale=1.0 donnent quasiment le meme temps (signe probable d'une
% limitation par l'adherence plutot que par le couple disponible).
%
% Resultat attendu si hypothese "limite adherence" correcte : le temps
% diminue avec la pedale jusqu'a un seuil, puis devient quasi plat.

clear; clc;

main_data_vehicle
modelName  = 'main_vehicle_v2';
simTime    = 10;
dt         = 0.001;
targetDist = 75;
signalName = 'PedalCmd';
uMin = 0;
uMax = 1;

load_system(modelName);

pedalValues = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 1.0];
crossTimes  = nan(size(pedalValues));

for i = 1:numel(pedalValues)
    p = pedalValues(i);
    params = [p, p, 0.01, 0.5, p, 0.01];  % pedale quasi constante (montee tres rapide)
    crossTimes(i) = simulateControlProfile(params, modelName, simTime, dt, ...
                                            targetDist, signalName, uMin, uMax);
    if isnan(crossTimes(i))
        fprintf('pedale = %.2f -> 75 m jamais atteint en %d s\n', p, simTime);
    else
        fprintf('pedale = %.2f -> temps 75 m = %.3f s\n', p, crossTimes(i));
    end
end

figure;
plot(pedalValues, crossTimes, 'o-', 'LineWidth', 1.5);
xlabel('Pedale constante (0-1)'); ylabel('Temps pour 75 m (s)');
grid on;
title('Temps de franchissement de 75 m vs pedale constante');