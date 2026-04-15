function out = myfactorial(n)

if n ~= 0
    out = n * myfactorial(n-1);
else
    out = 1;
end

end