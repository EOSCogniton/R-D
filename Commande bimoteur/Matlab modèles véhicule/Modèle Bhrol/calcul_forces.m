function [F]=calcul_forces(N1,N2,N3,N4,mux1,muy1,mux2,muy2,mux3,muy3,mux4,muy4)
F1=mux1*N1;
P1=muy1*N1;
F2=mux2*N2;
P2=muy2*N2;
F3=mux3*N3;
P3=muy3*N3;
F4=mux4*N4;
P4=muy4*N4;
F=[F1 P1 F2 P2 F3 P3 F4 P4];
end
