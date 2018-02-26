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

    printf("This project is prepared by\n1. Samip Poudel (074BCT533)\n2. Safal Thapaliya (074BCT531)\n3. Suraj Pandey (074BCT547)");
    toMain();
}

void toMain()
{
    gotoxy(20,20);
    printf("Press ESC to return to main menu");
    if(getch() == 27)
        main();
    else
        toMain();
}
