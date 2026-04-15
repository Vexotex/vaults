clc;
clear all;

A = [1,2,3,5;2,6,5,4;8,7,9,2;5,6,3,2];

% ----

n = size(A);

A_ = [A,eye(n)];

for s_idx = 1 : n(1)
    A_(s_idx,:) = A_(s_idx,:) / A_(s_idx,s_idx);
    for z_idx = 1 : n(1)
        if z_idx ~= s_idx
            A_(z_idx,:) = A_(z_idx,:) - A_(z_idx,s_idx) * A_(s_idx,:);
        end
    end
end

A_inv = A_(:,n(1)+1:end)