
KW_Start = 39;
starttag = -1;

fprintf(1,'\n\t\tMo\tDi\tMi\tDo\tFr\tSa\tSo\n');

for KW = KW_Start : KW_Start+4
    Woche    = (starttag : starttag + 6);
    for idx = 1 : 7
        if (Woche(idx)>0 && Woche(idx)<32)
            WocheStr{idx} = num2str(Woche(idx));
        else
            WocheStr{idx} = ' ';
        end
    end
    starttag = starttag + 7;
    fprintf(1,'KW%i\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n',...
        KW,WocheStr{1},WocheStr{2},WocheStr{3},WocheStr{4},...
        WocheStr{5},WocheStr{6},WocheStr{7});
end
    