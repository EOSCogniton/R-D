function J = costFunction_launch(params, modelName, simTime, dt, targetDist, signalName, uMin, uMax)
%COSTFUNCTION_LAUNCH Fonction cout pour l'optimisation du launch.
%   J = temps de franchissement de targetDist (en s).
%   Penalite forte si la distance n'est jamais atteinte OU si la
%   simulation echoue (cf. simulateControlProfile.m).

    crossTime = simulateControlProfile(params, modelName, simTime, dt, ...
                                        targetDist, signalName, uMin, uMax);

    if isnan(crossTime)
        J = 1000;
    else
        J = crossTime;
    end
end
