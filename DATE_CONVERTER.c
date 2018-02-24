#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "BStoAD.h"
#include "ADtoBS.h"
#include "extras.h"
#include "DayFinder.h"

void bsTOad(void);
void adTObs(void);
int main()
{
    x_axis(10,1,40);
    x_axis(10, 15, 40);
    y_axis(10,1, 15);
    y_axis(50, 1, 15);
    gotoxy(15,3);
    printf("+++++++DATE CONVERTER+++++++");

    gotoxy(14,5);
    printf("1. B.S to A.D");
    gotoxy(14,7);
    printf("2. A.D to B.S");
    gotoxy(14,9);
    printf("3. About the project");
    gotoxy(14,11);
    printf("4. Credits");
    gotoxy(14,13);
    printf("5. Exit");

    char press;
    option:
        fflush(stdin);
       press = getch();

    switch(press)
    {

    case '1':
        system("cls");
        bsTOad();
        break;
    case '2':
        system("cls");
        adTObs();
        break;
   /* case '3':
        system("cls");
        about();
        break;
    case '4':
        system("cls");
        credits();
        break;*/
    case '5':
        system("cls");
        exit(0);
    default:
        goto option;

    }

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
    if(n.y < 2000 || n.y > 2090)
       {
        out();
        fflush(stdin);
        goto year_1;
       }
    month_1:
    gotoxy(18,7);
    scanf("%d",&n.m);
    if(n.m < 1 || n.m >12)
        {
            out();
            fflush(stdin);
            goto month_1;
        }
    day_1:
    gotoxy(18,9);
    scanf("%d",&n.d);
    if(n.d < 1 || n.d > 32)
        {
            out();
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
    gotoxy(53,7);
    printf("%d",fe.m);
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
    if(E.y < 1934 || E.y > 2034)
       {
        out();
        fflush(stdin);
        goto year_1;
       }
    month_1:
    gotoxy(18,7);
    scanf("%d",&E.m);
    if(E.m < 1 || E.m >12)
        {
            out();
            fflush(stdin);
            goto month_1;
        }
    day_1:
    gotoxy(18,9);
    scanf("%d",&E.d);
    if(E.d < 1 || E.d > 31)
        {
            out();
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
    gotoxy(53,7);
    printf("%d",fn.m);
    gotoxy(53,9);
    printf("%d",fn.d);
    DayFind(E);
    end();
}
