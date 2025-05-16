function [mu]=Pacejka(lambda,B,C,D,E)
mu=D*cos(C*atan(B*lambda-E*(B*lambda-atan(B*lambda))));
end
