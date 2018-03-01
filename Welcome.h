void Welcome(int a,int b)
{
    int i;
    char s[80] , loa[]="LOADING", msgs[]="DATE CONVERTER";
    gotoxy(a,b-10);
    gotoxy(a,b);
    printf("[");
    //char s[]="------------------------------------------";
    for(i=0;i<79;i++)
    {
      s[i]='-';
      s[78]=']';
    printf("%c",s[i]);
    }
    int j=a;
    for(i=0;i<78;i++)
    {
        gotoxy(j+1,b);
        if(s[i]=='-' && (i<20||i>26)){
            printf("#");
        }
        else
        {
            printf("%c",loa[i-20]);
        }

        if(i<strlen(msgs)){
                gotoxy(j,b-1);
               printf("%c",msgs[i]);
        }
        if(i==15){
            gotoxy(a,b-6);
            printf("Suraj,");
        }
        if(i==30){
            gotoxy(a+6,b-5);
            printf("Samip");
        }
        if(i==45){
            gotoxy(a+11,b-4);
            printf("and Safal Presents...");
        }
                j++;
        Sleep(35);
    }
}
