#define UP 72
#define DOWN 80
int keys()
{

    int h=27, v=10;
    char keyPress;
    Opt:
    gotoxy(h,v);
    printf(">>");
    fflush(stdin);
    keyPress = getch();

    if(keyPress == 13)
        return v;
    else if (keyPress == UP)
    {
            // code for arrow up
            v=v-2;
            if(v<=10)
                {
                    gotoxy(h,v+2);
                    printf("  ");
                    v=10;
                    goto Opt;
                }
            gotoxy(h,v+2);
            printf("  ");
            goto Opt;

    }
       else if(keyPress == DOWN)// code for arrow down
           {
            v=v+2;
            if(v>=18){
                gotoxy(h,v-2);
                printf("  ");
                v=18;
                goto Opt;
            }
            gotoxy(h,v-2);
            printf("  ");
            goto Opt;
           }
        else
            goto Opt;
    }
