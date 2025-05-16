function [V_roues]=calcul_vitessesroues(Vx,Vy,phipoint,delta1,delta2,delta3,delta4,d_f,d_r,l_f,l_r)
t_f=d_f/2;
t_r=d_r/2;
delta=[delta1,delta2,delta3,delta4];
Vx1=(Vx-t_f*phipoint)*cos(delta(1))+(Vy+l_f*phipoint)*sin(delta(1));
Vy1=-(Vx-t_f*phipoint)*sin(delta(1))+(Vy+l_f*phipoint)*cos(delta(1));  %Vraie formule
%Vy1=Vx1*tan(delta1); %Force l'angle de glissement nul

Vx2=(Vx+t_f*phipoint)*cos(delta(2))+(Vy+l_f*phipoint)*sin(delta(2));
Vy2=-(Vx+t_f*phipoint)*sin(delta(2))+(Vy+l_f*phipoint)*cos(delta(2));
%Vy2=Vx2*tan(delta2);

Vx3=(Vx-t_r*phipoint)*cos(delta(3))+(Vy-l_r*phipoint)*sin(delta(3));
Vy3=-(Vx-t_r*phipoint)*sin(delta(3))+(Vy-l_r*phipoint)*cos(delta(3));

Vx4=(Vx+t_r*phipoint)*cos(delta(4))+(Vy-l_r*phipoint)*sin(delta(4));
Vy4=-(Vx+t_r*phipoint)*sin(delta(4))+(Vy-l_r*phipoint)*cos(delta(4));

V_roues=[Vx1 Vy1 Vx2 Vy2 Vx3 Vy3 Vx4 Vy4];
end
    