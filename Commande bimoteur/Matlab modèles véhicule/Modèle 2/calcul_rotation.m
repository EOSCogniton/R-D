function [Tr]=calcul_rotation(theta,phi,psi)
Tr=[cos(phi)*cos(psi), -sin(psi)*cos(phi)-cos(psi)*sin(theta)*sin(phi), sin(psi)*sin(phi)+cos(psi)*sin(theta)*cos(phi);
    sin(psi)*cos(theta), cos(psi)*cos(phi)+sin(psi)*sin(theta)*sin(phi), -cos(psi)*sin(phi)-sin(psi)*sin(theta)*cos(phi);
    sin(theta), cos(phi)*sin(theta), cos(theta)*sin(phi)];
end