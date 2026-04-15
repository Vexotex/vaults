function out = fvector(fhandle,in)

dim = size(in);

for idx1 = 1 : dim(1)
    for idx2 = 1 : dim(2)
        out(idx1,idx2) = feval(fhandle,in(idx1,idx2));
    end
end
