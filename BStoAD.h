typedef struct{
    int d;
    int m;
    int y;
} Date;

Date english(int,int);
Date ConvertToAD(Date);
void rewind2(void);

void bsTOad(void){

    system("cls");
    Date n,fe;
    gotoxy(12,2);
    printf("Date in B.S.");

    box1();

    date(10,5);
    year_1:
    gotoxy(18,5);
    scanf("%d",&n.y);
    EscOut();
    if(n.y < 2000 || n.y > 2090)
       {
        out();
        Back(18,5,n.y);
        fflush(stdin);
        goto year_1;
       }
    month_1:
    gotoxy(18,7);
    scanf("%d",&n.m);
    EscOut();
    if(n.m < 1 || n.m >12)
        {
            out();
            Back(18,7,n.m);
            fflush(stdin);
            goto month_1;
        }
    day_1:
    gotoxy(18,9);
    scanf("%d",&n.d);
    EscOut();
    if(n.d < 1 || n.d > 32)
        {
            out();
            Back(18,9,n.d);
            fflush(stdin);
            goto day_1;
        }
    if(n.d < 16 && n.m <=9 && n.y == 2000)
    {
        out();
        Back(18,9,n.d);
        Back(18,7,n.m);
        Back(18,5,n.y);
        goto year_1;
    }
    fe=ConvertToAD(n);
    gotoxy(45,2);
    printf("Date in A.D.");


    box2();
     gotoxy(43,11);
    printf("Weekday ");
    date(43,5);
    gotoxy(53,5);
    printf("%d",fe.y);
    EnglishMonth(fe.m);
    gotoxy(53,9);
    printf("%d",fe.d);
    DayFind(fe);
    rewind2();

    }

Date ConvertToAD(Date N)
{
    Date e,dateAD;
    int nDays,eDay,diff;
    nDays= ntotalDays(N);
    e.y=((N.m>9)||((N.m==9)&&(N.d>16)))?N.y-56:N.y-57;
    eDay=etotalDays(e);
    diff=nDays-eDay;
    dateAD=english(e.y,diff);
    return dateAD;
}


int ntotalDays(Date N)
{
    int i=0,no[13],sum=0,j;
    FILE *fptr;
    char line[41],ch;
    fptr = fopen("Array.txt","r");
    if(fptr == NULL){
        printf("The file cannot be loaded");
        exit(1);
    }
    while (i<=((N.y-2000))){
        fgets(line,41,fptr);
            sscanf(line,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&no[0],&no[1],&no[2],&no[3],&no[4],&no[5],&no[6],&no[7],&no[8],&no[9],&no[10],&no[11],&no[12]);
        if(i<(N.y-2000))
        {
            for (j=1;j<13;j++)
            {
                sum += no[j];
            }
        }
        else
        {
            for(j=1;j<N.m;j++)
            {
                sum += no[j];
            }
        }

        ch=fgetc(fptr);
        if(ch=='\n')
            i++;
    }

    return (sum+N.d);
}
int etotalDays(Date e)
{
    Date ref={13,04,1943};
    int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int norm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,ey=ref.y,sum=0,j;
    for(i=0;i<(e.y-ref.y);i++,ey++)
    {
        if ((ey % 4 ==0 && ey%100!=0)|| ey%400==0){
            for(j=0;j<12;j++)
            {
                sum +=leap[j];
            }
        }
        else
        {
            for(j=(ey==1943)?4:0;j<12;j++)
            {
                sum +=norm[j];
            }
        }
    }
    return(sum+17);
}
Date english(int ey,int diff)
{
    Date e;
    int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int norm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int j=0;
    do{
         if ((ey % 4 ==0 && ey%100!=0)|| ey%400==0)
                diff -=leap[j];
          else
                diff -=norm[j];
        j++;
    }while(diff>0);
    e.y=ey;
    e.m=j;
    e.d=((ey % 4 ==0 && ey%100!=0)|| ey%400==0)?diff+leap[j-1]:diff+norm[j-1];
    return e;
}

void rewind2(void)
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
        bsTOad();
    }
    else
        goto Rewind;
}



