function [z, p, k] = zpk_multi(varargin)
num = 1;
den = 1;

for index = 1 : 2 : nargin
  num = conv(num,varargin{index});  
  den = conv(den,varargin{index+1});   
end

z = roots(num);
p = roots(den);
k = num(length(num)-length(z))/den(length(den)-length(p));
end