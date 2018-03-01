Date NtotalDays(int ed);
Date ConvertToBS(Date);
void rewind1(void);

void adTObs(void)
{
    system("cls");
    Date E, fn;
    gotoxy(12,2);
    printf("Date in A.D.");

    box1();

    date(10,5);
    year_1:
    gotoxy(18,5);
    scanf("%d",&E.y);
    EscOut();
    if(E.y < 1943 || E.y > 2034)
       {
        out();
        Back(18,5,E.y);
        fflush(stdin);
        goto year_1;
       }
    month_1:
    gotoxy(18,7);

    scanf("%d",&E.m);
    EscOut();
    if(E.m < 1 || E.m >12)
        {
            out();
            Back(18,7,E.m);
            fflush(stdin);
            goto month_1;
        }
    day_1:
    gotoxy(18,9);

    scanf("%d",&E.d);

    EscOut();
    if(E.d < 1 || E.d > 31)
        {
            out();
            Back(18,9,E.d);
            fflush(stdin);
            goto day_1;
        }
    if((E.d < 13 && E.m <= 4 && E.y == 1943) || (E.d > 13 && E.m >=4 && E.y >= 2034))
    {
        out();
        Back(18,9,E.d);
        Back(18,7,E.m);
        Back(18,5,E.y);
        goto year_1;
    }

    fn=ConvertToBS(E);

    gotoxy(45,2);
    printf("Date in B.S.");


    box2();
     gotoxy(43,11);
    printf("Weekday ");
    date(43,5);
    gotoxy(53,5);
    printf("%d",fn.y);
    NepaliMonth(fn.m);
    gotoxy(53,9);
    printf("%d",fn.d);
    DayFind(E);
    rewind1();
}


Date ConvertToBS(Date e)
{
    Date n;
    int eDays;

    eDays=EtotalDays(e);
    n=NtotalDays(eDays);

    return n;
}
int EtotalDays(Date e)
{
    Date ref={13,04,1943};
    int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int norm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,ey=ref.y,sum=0,j,totalm=12;
    for(i=0;i<=(e.y-ref.y);i++,ey++)
    {
        if (i==e.y-ref.y){
            totalm=e.m-1;
        }

        if ((ey % 4 ==0 && ey%100!=0)|| ey%400==0){
            for(j=0;j<totalm;j++)
            {
                sum +=leap[j];
            }
        }
        else
        {
            for(j=(ey==1943)?4:0;j<totalm;j++)
            {
                sum +=norm[j];
            }
        }
    }
    return(sum+17+e.d);
}
Date NtotalDays(int ed)
{
    Date n;
    int month,i=0,no[13],sum=0,sum1=0,j,c=0;
    FILE *fptr;
    char line[41],ch;
    fptr = fopen("Array.txt","r");
    if(fptr == NULL){
        printf("The file cannot be loaded");
        exit(1);
    }
    while (1){
        fgets(line,41,fptr);
            sscanf(line,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&no[0],&no[1],&no[2],&no[3],&no[4],&no[5],&no[6],&no[7],&no[8],&no[9],&no[10],&no[11],&no[12]);

            for (j=1;j<13;j++)
            {
                sum += no[j];
                if (sum>=ed){

                                sum1=sum-no[j];

                break;
                }
            }
            if (sum>=ed)
            break;

        ch=fgetc(fptr);
        if(ch=='\n')
            i++;
    }
    n.y=2000+i;
    n.d=ed-sum1;
    n.m=j;
    return (n);
}

void rewind1(void)
{
    system("color 8A");
    gotoxy(10,21);
    for(i=0;i<60;i++)
        printf("%c",ch);
        gotoxy(20,18);
    printf("Want to convert another date? (y/n)");
    char YorN;
    Rewind:

    YorN = getch();

    if(YorN == 'N' || YorN == 'n')
       {
        system("cls");
        MainMenu();
       }
    else if(YorN == 'Y' || YorN == 'y')
    {
        system("cls");
        adTObs();
    }
    else
        goto Rewind;
}
