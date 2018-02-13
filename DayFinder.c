#include <stdio.h>
void Display(int);
int main()
{
    int monthc[12]={1,4,4,0,2,5,0,3,6,1,4,6};
    int date,month,year,year2,Rem;
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
    printf("Month:");
    scanf("%d",&month);
    fflush(stdin);
    if(month>12 || month<1)
    {
        printf("Out of range \n");
        goto err;
    }
    printf("Year:");
    scanf("%d",&year);
    fflush(stdin);
    year2=year%100;
    //year2=((((year%4==0)&&(year%100==0)&&(year%400==0))||((year%4==0)&&(year%100!=0)))&&((month==1)/*||(month==2)*/))?year2-1:year2;
    Rem=(year>=2000 && year<=2100)?((year2+(year2/4)+monthc[month-1]+date-1)%7):((year2+(year2/4)+monthc[month-1]+date)%7);
    printf("%d",Rem);
    if(month<6 && month%2==0)
    {
        if((month!=2&&date<=30)||(year2==(year%100)&&month==2&&date<=28)||(year2!=(year%100)&&month==2&&date<=29))
            Display(Rem);
            else
                printf("Out of range");
    }
    else if(month>6 && month%2!=0)
    {
        if(date<=30)
            Display(Rem);
    }
    else if(month==6)
    Display(Rem);
    else
        printf("Out of Range");
    return 0;
}
void Display(int a)
{
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

