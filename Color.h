#include <stdio.h>
//using ANSI Color codes to change the font color
void red()
{
    printf("\x1b[32m");//prints fonts in red color
}

void green()
{
    printf("\x1b[32m");//displays text in green color
}

void reset()
{
    printf("\x1b[0m");
}
