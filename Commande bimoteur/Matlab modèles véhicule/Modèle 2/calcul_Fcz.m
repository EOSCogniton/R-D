function [Fzc]=calcul_Fcz(theta,phi,thetapoint,phipoint,X1point,X2point,X3point,X4point,X1,X2,X3,X4,k1,k2,k3,k4,c1,c2,c3,c4,d_f,l_f,d_r,l_r)
tf=d_f/2;
tr=d_r/2;
Fcz1=k1*(X1+tf*sin(theta)-l_f*sin(phi));%+c1*(X1point+tf*thetapoint*cos(theta)-l_f*phipoint*cos(phi));
Fcz2=k2*(X2-tf*sin(theta)-l_f*sin(phi));%+c2*(X2point-tf*thetapoint*cos(theta)-l_f*phipoint*cos(phi));
Fcz3=k3*(X3+tr*sin(theta)+l_r*sin(phi));%+c3*(X3point+tr*thetapoint*cos(theta)+l_r*phipoint*cos(phi));
Fcz4=k4*(X4-tr*sin(theta)+l_r*sin(phi));%+c4*(X4point-tr*thetapoint*cos(theta)+l_r*phipoint*cos(phi));
Fzc=[Fcz1 Fcz2 Fcz3 Fcz4];

end
