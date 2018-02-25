#include <stdio.h>
#include <stdlib.h>
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
    else
    {
        switch(keyPress) { // the real value
        case 'w':
        case 'W':
            // code for arrow up
            v=v-2;
            if(v<10)
                keys();
            gotoxy(h,v+2);
            printf("  ");
            goto Opt;
            break;
        case 's':
        case 'S':// code for arrow down
            v=v+2;
            if(v>18){
                gotoxy(h,v-2);
                printf("  ");
                keys();
            }
            gotoxy(h,v-2);
            printf("  ");
            goto Opt;
            break;
        default:
            goto Opt;
    }
    }
}
