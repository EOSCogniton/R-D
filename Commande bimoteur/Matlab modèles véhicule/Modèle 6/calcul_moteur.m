function C_m = calcul_moteur(F1,P1,F2,P2,F3,P3,F4,P4,C_F1,C_F2,C_F3,C_F4,R1,R2,R3,R4,J1,J2,J3,J4,V1,V2,V3,V4,V1point,V2point,V3point,V4point,alpha1,alpha2,alpha3,alpha4,alpha1point,alpha2point,alpha3point,alpha4point)
C_m3 = J3/R3 * (V3point*cos(alpha3)-V3*alpha3point*sin(alpha3)) + C_F3 + R3*F3;
C_m4 = J4/R4 * (V4point*cos(alpha4)-V4*alpha4point*sin(alpha4)) + C_F3 + R4*F4;
C_m = [0 0 C_m3 C_m4];
end