function [t_vec, u_vec] = buildControlProfile(params, simTime, dt, uMin, uMax)
%BUILDCONTROLPROFILE Construit un profil temporel de commande u(t)
%(couple, pédale d'accélérateur, etc.) : montée exponentielle vers une
%cible, puis décroissance exponentielle continue (pas de saut de valeur).
%
%   [t_vec, u_vec] = buildControlProfile(params, simTime, dt, uMin, uMax)
%
%   params = [u0, upeak, tau_rise, t1, ufloor, k]
%       u0       : valeur initiale de la commande
%       upeak    : valeur "cible" de la phase de montée
%       tau_rise : constante de temps de montée (s)
%       t1       : instant de transition montée -> décroissance (s)
%       ufloor   : valeur asymptotique de la phase de décroissance
%       k        : taux de décroissance (1/s)
%
%   simTime, dt : durée totale et résolution du signal
%   uMin, uMax  : bornes physiques de la commande
%                 (ex: [0,400] pour un couple en Nm, [0,1] pour une pédale)

    u0       = params(1);
    upeak    = params(2);
    tau_rise = params(3);
    t1       = params(4);
    ufloor   = params(5);
    k        = params(6);

    t_vec = (0:dt:simTime)';
    u_vec = zeros(size(t_vec));

    % Phase 1 : montée exponentielle vers upeak
    idxRise = t_vec < t1;
    u_vec(idxRise) = u0 + (upeak - u0) * (1 - exp(-t_vec(idxRise)/tau_rise));

    % Valeur de continuité au point de transition t1
    u_at_t1 = u0 + (upeak - u0) * (1 - exp(-t1/tau_rise));

    % Phase 2 : décroissance exponentielle vers ufloor (continue en t1)
    idxDecay = ~idxRise;
    u_vec(idxDecay) = ufloor + (u_at_t1 - ufloor) * exp(-k*(t_vec(idxDecay) - t1));

    % Sécurité : on clippe dans [uMin, uMax]
    u_vec = min(max(u_vec, uMin), uMax);
end
