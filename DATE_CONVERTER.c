#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "BStoAD.h"
#include "ADtoBS.h"
#include "extras.h"
#include "DayFinder.h"
#include "Key.h"
#include "month.h"

void bsTOad(void);
void adTObs(void);

int main()
{
    system("color 1F");
    x_axis(20,5,40);
    x_axis(20, 21, 40);
    y_axis(20, 5, 16);
    y_axis(60, 5, 17);
    gotoxy(25,7);
    printf("+++++++DATE CONVERTER+++++++");

    gotoxy(30,10);
    printf("B.S to A.D");
    gotoxy(30,12);
    printf("A.D to B.S");
    gotoxy(30,14);
    printf("About the project");
    gotoxy(30,16);
    printf("Credits");
    gotoxy(30,18);
    printf("Exit");

    char press;
    option:

    fflush(stdin);
    press = keys();

    if(press == 10)
    {
        system("cls");
        bsTOad();
    }
    else if(press == 12)
        {
            system("cls");
            adTObs();
        }
    /*else if(press == 14)
        {
        system("cls");
        about();
        }
    else if (press == 16)
        {
        system("cls");
        credits();
        }*/
    else if(press == 18)
        {
        system("cls");
        system("color 07");
        exit(0);
        }
    else
        goto option;



    return 0;

}

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
    end();

    }

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
    if(E.y < 1934 || E.y > 2034)
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
    end();
}
