function [omega]=calcul_omegaackermann(alpha1,alpha2,alpha3,alpha4,Vx1,Vy1,Vx2,Vy2,Vx3,Vy3,Vx4,Vy4,R1,R2,R3,R4)

V1=calcul_retourvitesse(Vx1,Vy1);
V2=calcul_retourvitesse(Vx2,Vy2);
V3=calcul_retourvitesse(Vx3,Vy3);
V4=calcul_retourvitesse(Vx4,Vy4);

omega1=V1/R1*cos(alpha1);
omega2=V2/R2*cos(alpha2);
omega3=V3/R3*cos(alpha3);
omega4=V4/R4*cos(alpha4);


omega=[omega1 omega2 omega3 omega4];
