#include <stdio.h>
typedef struct{
    int d;
    int m;
    int y;
} Date;
Date ntotalDays(int ed);
int etotalDays(Date e);
int main()
{
    Date e,n;
    int eDays;
    printf("Enter a the Date in AD DD/MM/YYYY");
    scanf("%d/%d/%d",&e.d,&e.m,&e.y);
    eDays=etotalDays(e);
    n=ntotalDays(eDays);
    printf("The corresponding date in BS is %d/%d/%d", n.d,n.m,n.y);
    return 0;
}
int etotalDays(Date e)
{
    Date ref={13,04,1943};
    int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    int norm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,ey=ref.y,sum=0,j,totalm=12;
    for(i=0;i<=(e.y-ref.y);i++,ey++)
    {
        if (i==e.y-ref.y){
            totalm=e.m-1;
        }

        if ((ey % 4 ==0 && ey%100!=0)|| ey%400==0){
            for(j=0;j<totalm;j++)
            {
                sum +=leap[j];
            }
        }
        else
        {
            for(j=(ey==1943)?4:0;j<totalm;j++)
            {
                sum +=norm[j];
            }
        }
    }
    return(sum+17+e.d);
}
Date ntotalDays(int ed)
{
    Date n;
    int month,i=0,no[13],sum=0,sum1=0,j,c=0;
    FILE *fptr;
    char line[41],ch;
    fptr = fopen("Array.txt","r");
    if(fptr == NULL){
        printf("The file cannot be loaded");
        exit(1);
    }
    while (1){
        fgets(line,41,fptr);
            sscanf(line,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&no[0],&no[1],&no[2],&no[3],&no[4],&no[5],&no[6],&no[7],&no[8],&no[9],&no[10],&no[11],&no[12]);

            for (j=1;j<13;j++)
            {
                sum += no[j];
                if (sum>ed){

                                sum1=sum-no[j];

                break;
                }
            }
            if (sum>ed)
            break;

        ch=fgetc(fptr);
        if(ch=='\n')
            i++;
    }
    n.y=2000+i;
    n.d=ed-sum1;
    n.m=j;
    return (n);
}
