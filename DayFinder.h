#include <stdio.h>

void Display(int);
int DayFind(Date e)
{
    int monthc[12]={1,4,4,0,2,5,0,3,6,1,4,6};
    int Year2,Rem;

    fflush(stdin);
    Year2=e.y%100;
    monthc[0]=(((e.y%4==0)&&(e.y%100==0)&&(e.y%400==0))||((e.y%4==0)&&(e.y%100!=0)))?0:1;
    monthc[1]=(((e.y%4==0)&&(e.y%100==0)&&(e.y%400==0))||((e.y%4==0)&&(e.y%100!=0)))?3:4;
    Rem=(e.y>=2000 && e.y<=2100)?((Year2+(Year2/4)+monthc[e.m-1]+e.d-1)%7):((Year2+(Year2/4)+monthc[e.m-1]+e.d)%7);
    if(e.m<6 && e.m%2==0)
    {
            if(e.m!=2&&e.d<=30)
            Display(Rem);
            else if(((e.m==2)&&(((e.y%4==0)&&(e.y%100==0)&&(e.y%400==0))||((e.y%4==0)&&(e.y%100!=0)))&&(e.d<=29))||((e.m==2)&&~(((e.y%4==0)&&(e.y%100==0)&&(e.y%400==0))||((e.y%4==0)&&(e.y%100!=0)))&&(e.d<=28)))
            Display(Rem);
            else
            {
                gotoxy(20,20);
                printf("Out of range, error in finding the weekday!!");
            }
    }
    else if(e.m>6 && e.m%2!=0)
    {
        if(e.d<=30)
            Display(Rem);
    }
    else if(e.m==6)
    Display(Rem);
    else if(e.m<6 || e.m>6)
    Display(Rem);
    else
        {
            gotoxy(20,20);
            printf("Error!!");
        }

}
void Display(int a)
{
    gotoxy(53,11);
    switch(a){
case 1:
    printf("Sunday");
    break;
case 2:
    printf("Monday");
    break;
case 3:
    printf("Tuesday");
    break;
case 4:
    printf("Wednesday");
    break;
case 5:
    printf("Thursday");
    break;
case 6:
    printf("Friday");
    break;
case 0:
    printf("Saturday");
    break;
}
}

