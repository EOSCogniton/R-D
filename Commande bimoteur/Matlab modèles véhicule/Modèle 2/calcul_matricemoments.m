function [Matmoments]=calcul_matricemoments(N1,N2,N3,N4,Fx1,Fy1,Fx2,Fy2,Fx3,Fy3,Fx4,Fy4,ax,ay,z,d_f,d_r,M,h,l_f,l_r)
t_f=d_f/2;
t_r=d_r/2;
H=h+z;
Mtheta=(N1-N2)*t_f+(N3-N4)*t_r-M*ay*h;
Mphi=-(N1+N2)*l_f+(N3+N4)*l_r+M*ax*h;
Mpsi=(Fy1+Fy2)*l_f-(Fy3+Fy4)*l_r+(Fx2+Fx1)*t_f+(Fx4-Fx3)*t_r;

Matmoments=[Mtheta Mphi Mpsi]';
end
