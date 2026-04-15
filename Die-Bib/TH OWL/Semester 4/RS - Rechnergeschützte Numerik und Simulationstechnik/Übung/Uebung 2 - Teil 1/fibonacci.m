function out = fibonacci(n)

if n > 1
    out = fibonacci(n-1) + fibonacci(n-2);
elseif n == 1
    out = 1;
else
    out = 0;
end

end