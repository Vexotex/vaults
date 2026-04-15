clear all

A = [ 4 -1  1;...
     -2  5  1;...
      1 -2  5]
  
b = [ 1; 2; 0]


n = size(A);

D = eye(n);
D(1 : n(1)+1 : end) =  A(1 : n(1)+1 : end)

D_inv = eye(n);
D_inv(1 : n(1)+1 : end) =  1./A(1 : n(1)+1 : end)

LR = A - D

B = - D_inv*LR

b_ = D_inv*b

x = zeros(3,1)

for idx = 1 : 10
    x =  B *x + b_
end