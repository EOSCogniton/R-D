     function [res]=eqpfd(F_Gx,F_Gy,F_aerox,F_aeroy,Fx1,Fy1,Fx2,Fy2,Fx3,Fy3,Fx4,Fy4,psi,d_f,d_r,L_f,L_r,M,Iz)
t_r=d_r/2;
t_f=d_f/2;

Ax=((Fx1+Fx2+Fx3+Fx4+F_aerox+F_Gx)*cos(psi)-(Fy1+Fy2+Fy3+Fy4+F_aeroy+F_Gy)*sin(psi))/M;
Ay=((Fx1+Fx2+Fx3+Fx4+F_aerox+F_Gx)*sin(psi)+(Fy1+Fy2+Fy3+Fy4+F_aeroy+F_Gy)*cos(psi))/M;
psipointpoint=(((Fy1+Fy2)*L_f-(Fy3+Fy4)*L_r)+((Fx2-Fx1)*t_f+(Fx4-Fx3)*t_r))/Iz;
% Ax=(Fx1+Fx2+Fx3+Fx4+F_aerox+F_Gx)/M;
% Ay=(Fy1+Fy2+Fy3+Fy4+F_aeroy+F_Gy)/M;
res=[Ax,Ay,psipointpoint];
end
