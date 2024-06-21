function [N]=calcul_N(ax,ay,M,L,l_r,h,g)
l_f=L-l_r;
l=(l_f+l_r)/2;
mat1=[ay ax g]';
mat2=[-l_r*h/l -h l_r; l_r*h/l -h l_r; -l_f*h/l h l_f; l_f*h/l h l_f];
N=(M/(2*L)).*mat2*mat1;