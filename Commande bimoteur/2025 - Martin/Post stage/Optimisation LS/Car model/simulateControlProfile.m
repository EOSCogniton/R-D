function [crossTime, simOut, xCar] = simulateControlProfile(params, modelName, simTime, dt, targetDist, signalName, uMin, uMax)
%SIMULATECONTROLPROFILE Simule modelName avec un profil de commande u(t)
%(couple OU pédale, selon signalName/uMin/uMax) et renvoie le temps pour
%atteindre targetDist mètres.
%
%   [crossTime, simOut, xCar] = simulateControlProfile(params, modelName, simTime, dt, targetDist, signalName, uMin, uMax)
%
%   signalName : nom de la variable lue par le bloc From Workspace
%                (ex: 'PedalCmd')
%   uMin, uMax : bornes physiques de la commande (ex: [0,1] pour la pédale)
%
%   IMPORTANT : si la simulation échoue (ex: modèle pneu qui diverge parce
%   que la commande dépasse les limites physiques admissibles), cette
%   fonction NE PLANTE PAS le run d'optimisation : elle capture l'erreur
%   et renvoie crossTime = NaN, qui sera traduit en pénalité par
%   costFunction_launch.m. C'est crucial car patternsearch/ga vont
%   forcément explorer des zones non-physiques de l'espace de paramètres.

    [t_vec, u_vec] = buildControlProfile2(params, simTime, dt, uMin, uMax);

    % HYPOTHESE PAR DEFAUT : le bloc From Workspace attend un objet
    % timeseries. Si ton bloc attend le format "Array" [temps, valeur],
    % remplace les 2 lignes suivantes par : uSignal = [t_vec, u_vec];
    uSignal = timeseries(u_vec, t_vec);
    uSignal.Name = signalName;

    simIn = Simulink.SimulationInput(modelName);
    simIn = simIn.setVariable(signalName, uSignal);
    simIn = simIn.setModelParameter('StopTime', num2str(simTime));

    try
        simOut = sim(simIn);
    catch ME
        fprintf('  [sim echouee] %s | u0=%.3f upeak=%.3f t1=%.3f -> penalite\n', ...
                 ME.identifier, params(1), params(2), params(4));
        crossTime = NaN;
        simOut = [];
        xCar = [];
        return;
    end

    % --- Extraction de xCar ---
    try
        xCar = simOut.xCar;
    catch
        try
            xCar = simOut.get('xCar');
        catch ME2
            error(['Impossible de récupérer xCar depuis simOut. Vérifie que ' ...
                   '"Single simulation output" est activé (Model Settings > ' ...
                   'Data Import/Export) et que le bloc To Workspace s''appelle ' ...
                   'bien "xCar". Erreur originale : %s'], ME2.message);
        end
    end

    % --- Calcul du temps de franchissement de targetDist ---
    data = xCar.Data(:);
    time = xCar.Time(:);
    idx = find(data >= targetDist, 1, 'first');

    if isempty(idx)
        crossTime = NaN;
    elseif idx == 1
        crossTime = time(1);
    else
        x1 = data(idx-1); x2 = data(idx);
        t1c = time(idx-1); t2c = time(idx);
        if x2 == x1
            crossTime = t1c;
        else
            crossTime = t1c + (targetDist - x1)/(x2 - x1)*(t2c - t1c);
        end
    end
end
