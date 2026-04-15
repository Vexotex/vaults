function out = pascal(n,m)

if (m == 0) || (m == n)
    out = 1;
else
    out = pascal(n-1,m-1) + pascal(n-1,m);
end

end