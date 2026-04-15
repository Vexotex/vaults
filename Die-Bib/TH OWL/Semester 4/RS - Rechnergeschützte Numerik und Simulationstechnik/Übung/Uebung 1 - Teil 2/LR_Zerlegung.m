function [L,R,L_] = LR_Zerlegung(A)

n = size(A);

A_ = [A,eye(n)];

L = eye(n(1));

for s_idx = 1 : n(1) - 1
    for z_idx = s_idx + 1 : n(1)
        L(z_idx,s_idx) = A_(z_idx,s_idx)/ A_(s_idx,s_idx);
        A_(z_idx,:) = A_(z_idx,:) - A_(z_idx,s_idx)/ A_(s_idx,s_idx) * A_(s_idx,:);
    end
end

R  = A_(:,1:n(1));
L_ = A_(:,n(1)+1:end);

end
