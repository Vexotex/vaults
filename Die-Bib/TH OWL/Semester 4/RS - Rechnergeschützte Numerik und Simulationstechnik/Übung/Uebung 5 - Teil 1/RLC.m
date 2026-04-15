function dx = RLC(t,x,R,L,C,ue,uet) 
    dx = zeros(2,1); %x1=iL x2=uC
    ue = interp1(uet,ue,t); % Interp. the data set (uit,ui) at time t
   %dx(1) = -1/L*x(2)+1/L*ue; 
   %dx(2) = 1/C*x(1)-1/(R*C)*x(2); 
    dx(1) = -R/L*x(1)-1/L*x(2)+1/L*ue; 
    dx(2) = 1/C*x(1); 
end
