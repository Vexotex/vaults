function y = exp_fun (x)

k=fix(x)+1;
norm=1/(exp(1)-1);
if mod(k,2)~=0
    y=(exp(x-fix(x))-1)*norm;
else
    y=(exp(1)-exp(x-fix(x)))*norm;
end
end