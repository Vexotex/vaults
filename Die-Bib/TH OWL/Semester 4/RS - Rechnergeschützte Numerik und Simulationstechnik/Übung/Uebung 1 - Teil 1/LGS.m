clc;
clear all

%         x*A = x*(b*c - A) + c
%    <=>  x*A - x*(b*c - A) = c
%    <=>  x * (A - b*c + A) = c
%    <=>  x * (2*A - b*c)   = c
%    <=>  x = c *inv(2*A - b*c)

A = [1,2;3,4];
b = [1;3];
c = [1,2];

x = c *inv(2*A - b*c)