function [omega]=retourlambda(lambdax1,lambday1,lambdax2,lambday2,lambdax3,lambday3,lambdax4,lambday4,Vx1,Vy1,Vx2,Vy2,Vx3,Vy3,Vx4,Vy4,R1,R2,R3,R4,accel)

if accel>0
    w1=Vx1/(R1*(1-lambdax1));
    w2=Vx2/(R2*(1-lambdax2));
    w3=Vx3/(R3*(1-lambdax3));
    w4=Vx4/(R4*(1-lambdax4));
    if lambdax1==1
        w1=Vx1/R1;
    end
    if lambdax2==1
        w2=Vx2/R2;
    end    
    if lambdax3==1
        w3=Vx3/R1;
    end
    if lambdax4==1
        w4=Vx4/R4;
    end
else
    w1=Vx1/R1*(1-lambdax1);
    w2=Vx2/R2*(1-lambdax2);
    w3=Vx3/R3*(1-lambdax3);
    w4=Vx4/R4*(1-lambdax4);
end
omega=[w1 w2 w3 w4];