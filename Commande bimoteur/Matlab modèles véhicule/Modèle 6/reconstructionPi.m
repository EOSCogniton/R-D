function [FiPi]=reconstructionPi(F1,F2,F3,F4,mux1,muy1,mux2,muy2,mux3,muy3,mux4,muy4)

P1=muy1/mux1*F1;
P2=muy2/mux2*F2;
P3=muy3/mux3*F3;
P4=muy4/mux4*F4;

if abs(mux1)<=0.1
    P1=0;
end
if abs(mux2)<=0.1
    P2=0;
end
if abs(mux3)<=0.1
    P3=0;
end
if abs(mux4)<=0.1
    P4=0;
end
FiPi=[F1 P1 F2 P2 F3 P3 F4 P4];
