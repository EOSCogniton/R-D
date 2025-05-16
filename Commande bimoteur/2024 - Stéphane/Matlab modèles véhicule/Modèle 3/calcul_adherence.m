function [mu]=calcul_adherence(lambdax1,lambday1,lambdax2,lambday2,lambdax3,lambday3,lambdax4,lambday4,Cte_1,Cte_2,Cte_3,Cte_4,N1,N2,N3,N4)

mux1=Cte_3*cos(Cte_2*atan(Cte_1*lambdax1-Cte_4*(Cte_1*lambdax1-atan(Cte_1*lambdax1))));%/N1;
muy1=Cte_3*cos(Cte_2*atan(Cte_1*lambday1-Cte_4*(Cte_1*lambday1-atan(Cte_1*lambday1))));%/N1;
mux2=Cte_3*cos(Cte_2*atan(Cte_1*lambdax2-Cte_4*(Cte_1*lambdax2-atan(Cte_1*lambdax2))));%/N2;
muy2=Cte_3*cos(Cte_2*atan(Cte_1*lambday2-Cte_4*(Cte_1*lambday2-atan(Cte_1*lambday2))));%/N2;
mux3=Cte_3*cos(Cte_2*atan(Cte_1*lambdax3-Cte_4*(Cte_1*lambdax3-atan(Cte_1*lambdax3))));%/N3;
muy3=Cte_3*cos(Cte_2*atan(Cte_1*lambday3-Cte_4*(Cte_1*lambday3-atan(Cte_1*lambday3))));%/N3;
mux4=Cte_3*cos(Cte_2*atan(Cte_1*lambdax4-Cte_4*(Cte_1*lambdax4-atan(Cte_1*lambdax4))));%/N4;
muy4=Cte_3*cos(Cte_2*atan(Cte_1*lambday4-Cte_4*(Cte_1*lambday4-atan(Cte_1*lambday4))));%/N4;

mu=[mux1 muy1 mux2 muy2 mux3 muy3 mux4 muy4];
end
