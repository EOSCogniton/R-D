function [omegapoint]=calcul_omega(F1,P1,F2,P2,F3,P3,F4,P4,Cm1,Cm2,Cm3,Cm4,Cf1,Cf2,Cf3,Cf4,ax,ay,R1,R2,R3,R4,J1,J2,J3,J4)
omegapoint1=(Cm1-R1*F1-Cf1);%+J1*ax/R1
omegapoint2=(Cm2-R2*F2-Cf2);%+J2*ax/R2
omegapoint3=(Cm3-R3*F3-Cf3);%+J3*ax/R3
omegapoint4=(Cm4-R4*F4-Cf4);%+J4*ax/R4
omegapoint=[omegapoint1 omegapoint2 omegapoint3 omegapoint4];
end
