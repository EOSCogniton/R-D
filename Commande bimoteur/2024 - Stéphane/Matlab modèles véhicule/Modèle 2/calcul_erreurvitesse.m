function [Erreur]=calcul_erreurvitesse(erreur,delta)
Erreur=[erreur*cos(delta) erreur*sin(delta)];
end