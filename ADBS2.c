#include <stdio.h>
typedef struct{
    int d;
    int m;
    int y;
} Date;
int ntotalDays(Date);
int etotalDays(Date);
Date english(int,int);
int main()
{
    Date n,e,fe;
    int nDays,eDay,diff;
    printf("Enter day , month and year in BS from(2000-2090) DD/MM/YYYY");
    scanf("%d/%d/%d",&n.d,&n.m,&n.y);
    nDays= ntotalDays(n);
    e.y=((n.m>9)||((n.m==9)&&(n.d>16)))?n.y-56:n.y-57;
    eDay=etotalDays(e);
    diff=nDays-eDay;
    fe=english(e.y,diff);
    printf("The corresponding AD date is %d/%d/%d",fe.y,fe.m,fe.d);
    return 0;
}
int ntotalDays(Date n)
{
    int i=0,no[13],sum=0,j;
    FILE *fptr;
    char line[41],ch;
    fptr = fopen("Array.txt","r");
    if(fptr == NULL){
        printf("The file cannot be loaded");
        exit(1);
    }
    while (i<=((n.y-2000))){
        fgets(line,41,fptr);
            sscanf(line,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&no[0],&no[1],&no[2],&no[3],&no[4],&no[5],&no[6],&no[7],&no[8],&no[9],&no[10],&no[11],&no[12]);
        if(i<(n.y-2000))
        {
            for (j=1;j<13;j++)
            {
                sum += no[j];
            }
        }
        else
        {
            for(j=1;j<n.m;j++)
            {
                sum += no[j];
            }
        }

        ch=fgetc(fptr);
        if(ch=='\n')
            i++;
    }

    return (sum+n.d);
}
int etotalDays(Date e)
{
    Date ref={13,04,1943};
    int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int norm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,ey=ref.y,sum=0,j;
    for(i=0;i<(e.y-ref.y);i++,ey++)
    {
        if ((ey % 4 ==0 && ey%100!=0)|| ey%400==0){
            for(j=0;j<12;j++)
            {
                sum +=leap[j];
            }
        }
        else
        {
            for(j=(ey==1943)?4:0;j<12;j++)
            {
                sum +=norm[j];
            }
        }
    }
    return(sum+17);
}
Date english(int ey,int diff)
{
    Date e;
    int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int norm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int j=0;
    do{
         if ((ey % 4 ==0 && ey%100!=0)|| ey%400==0)
                diff -=leap[j];
          else
                diff -=norm[j];
        j++;
    }while(diff>0);
    e.y=ey;
    e.m=j;
    e.d=((ey % 4 ==0 && ey%100!=0)|| ey%400==0)?diff+leap[j-1]:diff+norm[j-1];
    return e;
}
