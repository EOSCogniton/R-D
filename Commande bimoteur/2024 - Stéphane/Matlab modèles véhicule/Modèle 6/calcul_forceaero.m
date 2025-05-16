function [Faero]=calcul_forceaero(Vx,Vy,psi,Vventx,Vventy,C_x,A_L,A_S,rho)
Faero_x=-C_x*A_L*rho/2*(Vx-Vventx*cos(psi)-Vventy*sin(psi))^2;
Faero_y=-C_x*A_S*rho/2*(Vy-Vventy*cos(psi)+Vventx*sin(psi))^2;

Faero=[Faero_x Faero_y]';
end
