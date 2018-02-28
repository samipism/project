#include <stdio.h>
#include <stdlib.h>

void Display(int);
int main()
{
    int e.mc[12]={1,4,4,0,2,5,0,3,6,1,4,6};
    int date,e.m,year,year2,Rem;
    printf("++++++HELLO++++++\n");
    printf("DAY FINDER \n");
    derr:
    printf("Date:");
    scanf("%d",&date);
    fflush(stdin);
    if(date>31 || date<1)
    {
        printf("Out of range \n");
        goto derr;
    }
    err:
    printf("e.m:");
    scanf("%d",&e.m);
    fflush(stdin);
    if(e.m>12 || e.m<1)
    {
        printf("Out of range \n");
        goto err;
    }
    printf("Year:");
    scanf("%d",&year);
    fflush(stdin);
    year2=year%100;
    e.mc[0]=(((year%4==0)&&(year%100==0)&&(year%400==0))||((year%4==0)&&(year%100!=0)))?0:1;
    e.mc[1]=(((year%4==0)&&(year%100==0)&&(year%400==0))||((year%4==0)&&(year%100!=0)))?3:4;
    Rem=(year>=2000 && year<=2100)?((year2+(year2/4)+e.mc[e.m-1]+date-1)%7):((year2+(year2/4)+e.mc[e.m-1]+date)%7);
    printf("%d",Rem);
    if(e.m<6 && e.m%2==0)
    {
            if(e.m!=2&&date<=30)
            Display(Rem);
            else if(((e.m==2)&&(((year%4==0)&&(year%100==0)&&(year%400==0))||((year%4==0)&&(year%100!=0)))&&(date<=29))||((e.m==2)&&~(((year%4==0)&&(year%100==0)&&(year%400==0))||((year%4==0)&&(year%100!=0)))&&(date<=29)))
            Display(Rem);
            else
            {
                gotoxy(20,20);
                system("color 4");
                printf("Out of range, error in finding the weekday!!");
            }
    }
    else if(e.m>6 && e.m%2!=0)
    {
        if(date<=30)
            Display(Rem);
    }
    else if(e.m==6)
    Display(Rem);
    else if(e.m<6 || e.m>6)
    Display(Rem);
    else
        break;

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

