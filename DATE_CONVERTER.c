#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "extras.h"
#include "month.h"
#include "BStoAD.h"
#include "ADtoBS.h"
#include "DayFinder.h"
#include "Key.h"
#include "about.h"

void bsTOad(void);
void adTObs(void);

int main()
{
    system("cls");
    system("color 8F");
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
    press = keys();

    if(press == 10)
            bsTOad();
    else if(press == 12)
        adTObs();

    else if(press == 14)
        about();

    else if (press == 16)
        credits();

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
