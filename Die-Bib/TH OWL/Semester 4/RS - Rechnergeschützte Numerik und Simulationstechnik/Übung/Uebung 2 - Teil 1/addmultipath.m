function addmultipath(workdir)

addpath(workdir);
content = dir(workdir);

for idx = 3 : length(content)
    if content(idx).isdir
        addmultipath([workdir,'\',content(idx).name])
    end
end


end