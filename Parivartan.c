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
#include "Welcome.h"


void MainMenu(void);

int main()
{

    system("cls");
    Welcome(20,30);
    Sleep(1000);

    MainMenu();
    return 0;

}

void MainMenu(void)
{
    system("cls");
    system("color 8F");
    x_axis(20,5,40);
    x_axis(20, 21, 40);
    y_axis(20, 5, 16);
    y_axis(60, 5, 17);
    gotoxy(32,7);
    printf("PARIVARTAN");
    gotoxy(32,8);
    unsigned char c=196;
    for(i = 0; i<10; i++)
        printf("%c",c);

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

}
