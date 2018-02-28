COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left corner of the screen
 void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 unsigned char ch=177;
 int i;
void end(void)
{
    system("color 8A");
    NoPress:
    gotoxy(20,20);
    printf("Press ESC to return to main menu");
    gotoxy(10,21);
    for(i=0;i<60;i++)
        printf("%c",ch);
    if(getch()==27)
       {
        system("cls");
       main();
       }
    else
        goto NoPress;
}

    void x_axis(int x, int y, int len)//for border along the x-axis
    {//takes position of x, y and length of the box as arguments

        gotoxy(x,y);
        for(i=0;i<len;i++){
            gotoxy(x+i,y);
            printf("%c",ch);
    }
    }

    void y_axis(int x, int y, int len)//for border along the y-axis
    {//takes position of x , y and breadth of the box as arguments

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
        system("color 8C");
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

    void EscOut()
    {
        gotoxy(20,20);
        system("color 8F");
        for (i=0; i <36;i++)
            printf(" ");
    }

    void Back(int x,int y,int n)
    {
        gotoxy(x,y);
        int IntLen =0;
        while(n >0)
        {
            n=n/10;
            IntLen++;
        }

        for(i=0; i<IntLen; i++)
        printf(" ");
    }
