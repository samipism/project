#include <stdio.h>

void EnglishMonth(int m)
{
    gotoxy(53,7);
    switch(m)
    {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    }
}

void NepaliMonth(int m)
{
    gotoxy(53,7);
    switch(m)
    {
    case 1:
        printf("Baisakh");
        break;
    case 2:
        printf("Jestha");
        break;
    case 3:
        printf("Ashad");
        break;
    case 4:
        printf("Shrawan");
        break;
    case 5:
        printf("Bhadra");
        break;
    case 6:
        printf("Ashwin");
        break;
    case 7:
        printf("Kartik");
        break;
    case 8:
        printf("Mangsir");
        break;
    case 9:
        printf("Poush");
        break;
    case 10:
        printf("Magh");
        break;
    case 11:
        printf("Falgun");
        break;
    case 12:
        printf("Chaitra");
        break;
    }
}

