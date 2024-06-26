function values = check_zeros_8(v1,v2,v3,v4,v5,v6,v7,v8,epsilon)
values = [0 0 0 0 0 0 0 0];
if v1>epsilon
    values(1)=v1;
end
if v2>epsilon
    values(2)=v2;
end
if v3>epsilon
    values(3)=v3;
end
if v4>epsilon
    values(4)=v4;
end
if v5>epsilon
    values(5)=v5;
end
if v6>epsilon
    values(6)=v6;
end
if v7>epsilon
    values(7)=v7;
end
if v8>epsilon
    values(8)=v8;
end


end