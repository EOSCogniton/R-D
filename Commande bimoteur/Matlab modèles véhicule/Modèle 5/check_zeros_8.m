function values = check_zeros_8(v1,v2,v3,v4,v5,v6,v7,v8,epsilon)
values = [0 0 0 0 0 0 0 0];
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
if abs(v5)>epsilon
    values(5)=v5;
end
if abs(v6)>epsilon
    values(6)=v6;
end
if abs(v7)>epsilon
    values(7)=v7;
end
if abs(v8)>epsilon
    values(8)=v8;
end


end