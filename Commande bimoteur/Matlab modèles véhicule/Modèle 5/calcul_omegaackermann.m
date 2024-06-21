function [omega]=calcul_omegaackermann(Vx,Vy,psipoint,delta1,delta2,delta3,delta4,Vx1,Vy1,Vx2,Vy2,Vx3,Vy3,Vx4,Vy4,R1,R2,R3,R4,d_r,d_f,l_r,l_f)

t_f=d_f/2;
t_r=d_r/2;

V1=calcul_retourvitesse(Vx1,Vy1);
V2=calcul_retourvitesse(Vx2,Vy2);
V3=calcul_retourvitesse(Vx3,Vy3);
V4=calcul_retourvitesse(Vx4,Vy4);

omega1=V1/R1*cos(atan((Vx-psipoint*t_f)/(Vy+psipoint*l_f))-delta1);
omega2=V2/R2*cos(atan((Vx+psipoint*t_f)/(Vy+psipoint*l_f))-delta2);
omega3=V3/R3*cos(atan((Vx-psipoint*t_r)/(Vy-psipoint*l_r))-delta3);
omega4=V4/R4*cos(atan((Vx+psipoint*t_r)/(Vy-psipoint*l_r))-delta4);

if (Vy+psipoint*l_f)==0
    omega1=0;
    omega2=0;
end
if (Vy-psipoint*l_r)==0
    omega3=0;
    omega4=0;
end

omega=[omega1 omega2 omega3 omega4];
