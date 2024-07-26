function [Tr]=calcul_rotaroute(theta,phi)
Tr=[cos(phi) sin(phi)*sin(theta) sin(phi)*cos(theta); 0 cos(theta) -sin(theta); -sin(phi) cos(phi)*sin(theta) cos(phi)*cos(theta)];
end
