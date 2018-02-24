#include <stdio.h>

void Display(int);
void DayFind(Date e)
{
    int monthc[12]={1,4,4,0,2,5,0,3,6,1,4,6};
    int year2,Rem;

    year2=e.y%100;
    //year2=((((year%4==0)&&(year%100==0)&&(year%400==0))||((year%4==0)&&(year%100!=0)))&&((month==1)/*||(month==2)*/))?year2-1:year2;
    Rem=(e.y>=2000 && e.y<=2100)?((year2+(year2/4)+monthc[e.m-1]+e.d-1)%7):((year2+(year2/4)+monthc[e.m-1]+e.d)%7);

    if(e.m<6 && e.m%2==0)
    {
        if((e.m!=2&&e.d<=30)||(year2==(e.y%100)&&e.m==2&&e.d<=28)||(year2!=(e.y%100)&&e.m==2&&e.d<=29))
            Display(Rem);

    }
    else if(e.m>6 && e.m%2!=0)
    {
        if(e.d<=30)
            Display(Rem);
    }
    else if(e.m==6)
    Display(Rem);

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

