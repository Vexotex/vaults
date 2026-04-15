hold off

for c = 0.1 : 0.1 : 1
    sim('smd_smart');
    plot(simout.Time,simout.Data)
    hold on;
end

grid on;