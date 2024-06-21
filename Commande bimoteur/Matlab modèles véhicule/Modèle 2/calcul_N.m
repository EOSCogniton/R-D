function [N]=calcul_N(ax,ay,z,M,L,l_r,h,g)
l_f=L-l_r;
H=h;%+z;
mat1=[ay ax g]';
mat2=[-l_r*H/L -H l_r; l_r*H/L -H l_r; -l_f*H/L H l_f; l_f*H/L H l_f];
N=(M/2*L).*mat2*mat1;