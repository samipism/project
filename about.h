void toMain(void);
void about()
{
    system("cls");
    printf("This is date converter that converts date from\nA.D to B.S and B.S to A.D");
    toMain();
}

void credits()
{
    system("cls");
    system("color 8F");
    gotoxy(4,3);
    puts("This project is prepared by");
    gotoxy(4,5);
    puts("1. Samip Poudel (074BCT533)");
    gotoxy(4,7);
    puts("2. Safal Thapaliya (074BCT531)");
    gotoxy(4,9);
    puts("3. Suraj Pandey (074BCT547)");
    toMain();
}

void toMain()
{
    if(getch() == 27)
        MainMenu();
    else
        toMain();
}
