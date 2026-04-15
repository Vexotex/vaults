figure(1);
hold off;
[x,y,z] = sphere(100);
surfl(x+2,y,z);
ahandle =gca;
hold on;
surfl(x-2,y,z);
[x,y,z] = cylinder(ones(50));
surfl((z-0.5)*2.5,0.5*y,0.5*x);
cm = gray(1000);
cm(:,3)= 0 * cm(:,3);
cm = cm(500:1000,:);
colormap(cm);
shading interp;
set(ahandle,'XGrid','off','YGrid','off','ZGrid','off');
set(ahandle,'XColor',[1,1,1],'YColor',[1,1,1],'ZColor',[1,1,1]);
set(gcf,'Color',[1,1,1]);


for idx = 0 : 1 : 4*360
    view(idx,20)
    pause(0.01);
end
    