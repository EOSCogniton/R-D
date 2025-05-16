function C_m = calcul_moteur(F1,P1,F2,P2,F3,P3,F4,P4,C_F1,C_F2,C_F3,C_F4,R1,R2,R3,R4,J1,J2,J3,J4)
C_m3 = J3/J1 * (-R1*F1 - C_F1) + C_F3 + R3*F3;
C_m4 = J4/J2 * (-R2*F2 - C_F2) + C_F4 + R4*F4;
C_m = [0 0 C_m3 C_m4];
end