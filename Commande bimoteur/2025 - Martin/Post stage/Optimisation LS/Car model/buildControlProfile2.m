function [t_vec, u_vec] = buildControlProfile2(params, simTime, dt, uMin, uMax)
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

    for i=1:11
        u(i)=params(i);
    end

    t_breakpoints=0:0.4:4;


    t_vec = (0:dt:simTime)';
    % u_vec = zeros(size(t_vec));

    u_vec=interp1(t_breakpoints,u,t_vec,'pchip');

    % Sécurité : on clippe dans [uMin, uMax]
    u_vec = min(max(u_vec, uMin), uMax);
end
