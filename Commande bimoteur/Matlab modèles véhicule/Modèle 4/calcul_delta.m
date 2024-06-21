function [Mat_delta]=calcul_delta(delta,L,d_f)
delta_1=atan(L*tan(delta)/(L-d_f/2*tan(delta)));
delta_2=atan(L*tan(delta)/(L+d_f/2*tan(delta)));
delta_3=0;
delta_4=0;
Mat_delta=[delta_1, delta_2, delta_3, delta_4];
end
