function changecolor(allhandle)

red = get(allhandle.red,'Value');
blue = get(allhandle.blue,'Value');
green = get(allhandle.green,'Value');

set(allhandle.fig,'Color',[red,green,blue]);

end