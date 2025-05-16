lambdatest=linspace(-1,1,1000);
mutest=Cte_3.*cos(Cte_2*atan(Cte_1.*lambdatest-Cte_4*(Cte_1.*lambdatest-atan(Cte_1.*lambdatest))));%/N1;
plot(lambdatest,mutest)