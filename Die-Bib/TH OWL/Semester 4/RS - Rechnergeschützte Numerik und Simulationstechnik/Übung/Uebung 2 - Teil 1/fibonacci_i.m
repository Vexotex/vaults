function out = fibonacci_i(n)

out_1 = 1;
out_2 = 0;

for index = 1 : n - 1
   out = out_1 + out_2;
   out_2 = out_1;
   out_1 = out;
end

end