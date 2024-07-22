function [cmot]=calcul_couplemot(F1,F2,F3,F4,Cf1,Cf2,Cf3,Cf4,R1,R2,R3,R4,J1,J2,J3,J4)

Cm_g=J3/J1*(-R1*F1-Cf1)+Cf3+R3*F3;
Cm_d=J4/J2*(-R2*F2-Cf2)+Cf4+R4*F4;

cmot=[0 0 Cm_g Cm_d];