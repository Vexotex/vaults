fun = inline('2*sin(x)-x');

x = linspace(-5,5,1000);
plot(x,fun(x));
grid on

e_max = 1e-12;

x_k_1  = 1.5;
x_k    = 2.5;
x_kp1_ = 0;
n     = 0;

while abs(x_kp1_ - x_kp1) > e_max
    n = n+1
    x_kp1_ = x_kp1;
    x_kp1  = x_k - fun(x_k) * (x_k_1 - x_k) / (fun(x_k_1) - fun(x_k))
    if fun(x_k) * fun(x_kp1) < 0
        x_k_1 = x_kp1;
    else
        x_k = x_kp1;
    end
end