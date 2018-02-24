#include<stdio.h>
#include <windows.h>
COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left corner of the screen
 void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 unsigned char ch=178;
void end(void)
{
    int i;

    gotoxy(20,20);
    printf("Press any key to continue...");
    gotoxy(10,21);
    for(i=0;i<60;i++)
        printf("%c",ch);
    while(getch())
       {
        system("cls");
       main();
       }
}

    void x_axis(int x, int y, int len)//for border along the x-axis
    {//takes position of x, y and length of the box as arguments
        int i;
        gotoxy(x,y);
        for(i=0;i<len;i++){
            gotoxy(x+i,y);
            printf("%c",ch);
    }
    }

    void y_axis(int x, int y, int len)//for border along the y-axis
    {//takes position of x , y and breadth of the box as arguments
        int i;
        gotoxy(x,y);
         for(i=0; i<len;i++)
    {
        gotoxy(x,y+i);
        printf("%c\n",ch);
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
        int i;
        char outRange[]="OUT OF RANGE!!!Please enter again...";
        gotoxy(20,20);
        printf("%s",outRange);
    }

    void box1(void)
    {
        y_axis(7,3,9);
        y_axis(31,3,9);
        x_axis(7,3,25);
        x_axis(7,11,25);
    }
    void box2(void)
    {
        x_axis(41,3,25);
        x_axis(41,13,25);
        y_axis(41,3,11);
        y_axis(65,3,11);

    }
