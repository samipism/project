#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
 COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left corner of the screen
 void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void x_axis(int,int,int);
 void y_axis(int,int,int);
 void date(int, int);
 void out(void);
 int i;//global variable

 void end(void);
int main()
{
    int year,month,day;
    gotoxy(25,0);
    printf("DATE CONVERTER");
    gotoxy(14,2);
    printf("Date in B.S.");

    y_axis(7,3,9);
    y_axis(31,3,9);
    x_axis(7,3,25);
    x_axis(7,11,25);

    date(10,5);
    year_1:
    gotoxy(18,5);
    scanf("%d",&year);
    if(year < 2000 || year > 2090)
       {
        out();
        goto year_1;
       }
    month_1:
    gotoxy(18,7);
    scanf("%d",&month);
    if(month < 1 || month >12)
        {
            out();
            goto month_1;
        }
    day_1:
    gotoxy(18,9);
    scanf("%d",&day);
    if(day < 1 || day > 32)
        {
            out();
            goto day_1;
        }

    gotoxy(45,2);
    printf("Date in B.S.");
    x_axis(41,3,25);
    x_axis(41,13,25);
    y_axis(41,3,11);
    y_axis(65,3,11);
    gotoxy(43,11);
    printf("Weekday ");
    date(43,5);

    end();
    return 0;
}

void end(void)
{
    int i;
    gotoxy(7,20);
    printf("Press 1 to continue...\t\tPress 2 to return to main menu");
    gotoxy(10,21);
    for(i=0;i<60;i++)
        printf("%c",220);
    char choice;
    recall:
        choice=getch();

    switch(choice)
    {
        //when user presses 1
    case '1':
        system("cls");
        main();
    case '2'://when user presses 2
        system("cls");
    default:
        goto recall;

    }
}

    void x_axis(int x, int y, int len)//for border along the x-axis
    {//takes position of x, y and length of the box as arguments
        gotoxy(x,y);
        for(i=0;i<len;i++){
            gotoxy(x+i,y);
            printf("%c",219);
    }
    }

    void y_axis(int x, int y, int len)//for border along the y-axis
    {//takes position of x , y and breadth of the box as arguments
        gotoxy(x,y);
         for(i=0; i<len;i++)
    {
        gotoxy(x,y+i);
        printf("%c\n",219);
    }
    }

    void date(int x, int y)//displaying the date format
    {//it takes the position of x and y as arguments
        gotoxy(x,y);
        printf("Year  ");
        gotoxy(x,y+2);
        printf("Month  ");
        gotoxy(x, y+4);
        printf("Day  ");
        }

    void out(void)
    {
        gotoxy(20,20);
        printf("OUT OF RANGE!!!Please enter again...");
    }
