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

 void func(void);
int main()
{
    int year,month,day,i;
    gotoxy(25,0);
    printf("A.D TO B.S CONVERTER");
    gotoxy(14,2);
    printf("Date in A.D.");
    gotoxy(8,3);
    for(i=0;i<25;i++){
            gotoxy(8+i,3);
            printf("%c",219);
            gotoxy(8+i,11);
            printf("%c",219);
    }
    gotoxy(7,4);
    for(i=0; i<9;i++)
    {
        gotoxy(7,3+i);
        printf("%c\n",219);
        gotoxy(33,3+i);
        printf("%c\n",219);
    }
    gotoxy(10,5);
    printf("Year  ");
    gotoxy(10,9);
    printf("Day  ");
    gotoxy(10, 7);
    printf("Month  ");

    gotoxy(45,2);
    printf("Date in B.S.");
    gotoxy(41,3);
     for(i=0;i<25;i++){
            gotoxy(41+i,3);
            printf("%c",219);
            gotoxy(41+i,11);
            printf("%c",219);
    }
    gotoxy(40,4);
    for(i=0; i<9;i++)
    {
        gotoxy(40,3+i);
        printf("%c\n",219);
        gotoxy(66,3+i);
        printf("%c\n",219);
    }
    gotoxy(43,5);
    printf("Year  ");
    gotoxy(43,9);
    printf("Day  ");
    gotoxy(43, 7);
    printf("Month  ");

    gotoxy(18,5);
    scanf("%d",&year);
    gotoxy(18,7);
    scanf("%d",&month);
    gotoxy(18,9);
    scanf("%d",&day);

    func();
    return 0;
}

void func(void)
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
