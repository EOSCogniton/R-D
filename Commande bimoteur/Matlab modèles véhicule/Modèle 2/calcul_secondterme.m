function [terme]=calcul_secondterme(theta,phi,thetapoint,phipoint,c1,c2,c3,c4,k1,k2,k3,k4,d_r,d_f,l_r,l_f)
tf=d_f/2;
tr=d_r/2;
terme1=-c1*tf*thetapoint*cos(theta)+c1*l_f*phipoint*cos(phi)+k1*l_f*sin(phi)+k1*tf*sin(theta);
terme2=c2*tf*thetapoint*cos(theta)+c2*l_f*phipoint*cos(phi)+k2*l_f*sin(phi)+k2*tf*sin(theta);
terme3=-c3*tr*thetapoint*cos(theta)-c3*l_r*phipoint*cos(phi)-k3*l_r*sin(phi)-k3*tr*sin(theta);
terme4=+c4*tr*thetapoint*cos(theta)-c4*l_r*phipoint*cos(phi)-k4*l_r*sin(phi)+k4*tr*sin(theta);
terme=[terme1 terme2 terme3 terme4];
end
