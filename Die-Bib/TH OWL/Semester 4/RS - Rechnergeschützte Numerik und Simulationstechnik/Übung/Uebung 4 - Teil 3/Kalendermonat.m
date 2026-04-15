
KW_Start = 39;
starttag = -1;

fprintf(1,'\n\t\tMo\tDi\tMi\tDo\tFr\tSa\tSo\n');

for KW = KW_Start : KW_Start+4
    Woche = (starttag : starttag + 6)...
        - 31 *((starttag : starttag + 6) > 31)...
        + 31 *((starttag : starttag + 6) < 1);
    starttag = starttag + 7;
    fprintf(1,'KW%i\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n',...
        KW,Woche(1),Woche(2),Woche(3),Woche(4),...
        Woche(5),Woche(6),Woche(7));
end
    
