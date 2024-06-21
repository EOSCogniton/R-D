function [lambda]=calcul_lambda(A)
u1=A(1);
u2=A(2);
u3=A(3);
u4=A(4);
v1=A(5);
v2=A(6);
v3=A(7);
v4=A(8);
w1=A(9);
w2=A(10);
w3=A(11);
w4=A(12);
Beta=A(13);
R=1;
ang=[cos(Beta) sin(Beta)];
calc=[u1/w1 v1/w1; u2/w2 v2/w2; u3/w3 0; u4/w4 0; v1/w1 -u1/w1; v2/w2 -u2/w2; v3/w3 0; v4/w4 0];
lambda=ones(8,1)-1/R*calc*ang';
lambda_i=[lambda(1) lambda(2) lambda(3) lambda(4)]';
lambda_v_i=[lambda(5) lambda(6) lambda(7) lambda(8)]';

end
