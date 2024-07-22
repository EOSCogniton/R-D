function [V]=calcul_normevitesseroue(Vx1,Vy1,Vx2,Vy2,Vx3,Vy3,Vx4,Vy4,Acons)

V1=calcul_retourvitesse(Vx1,Vy1,Acons);
V2=calcul_retourvitesse(Vx2,Vy2,Acons);
V3=calcul_retourvitesse(Vx3,Vy3,Acons);
V4=calcul_retourvitesse(Vx4,Vy4,Acons);

V=[V1 V2 V3 V4];
