function values = check_zeros_4(v1,v2,v3,v4,epsilon)
values = [0 0 0 0];
if abs(v1)>epsilon
    values(1)=v1;
end
if abs(v2)>epsilon
    values(2)=v2;
end
if abs(v3)>epsilon
    values(3)=v3;
end
if abs(v4)>epsilon
    values(4)=v4;
end

end