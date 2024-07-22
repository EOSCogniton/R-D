function [theta]=angle_moy(x,y)
if x==0
    theta=0;
else
    theta=atan(y/x);
end
end
