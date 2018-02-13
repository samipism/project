#include <stdio.h>
int totalDays(int,int,int);
int main()
{
    int nday,nmonth,nyear,Days;
    printf("Enter day , month and year in DD/MM/YYYY");
    scanf("%d/%d/%d",&nday,&nmonth,&nyear);
    Days= totalDays(nday,nmonth,nyear);
    printf("The sum is %d",Days);
    return 0;
}
int totalDays(int d,int m,int y)
{
    int i=0,no[13],sum=0,j;
    FILE *fptr;
    char line[41],ch;
    fptr = fopen("Array.txt","r");
    if(fptr == NULL){
        printf("The file cannot be loaded");
        exit(1);
    }
    while (i<=((y-2000))){
        fgets(line,41,fptr);
            sscanf(line,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&no[0],&no[1],&no[2],&no[3],&no[4],&no[5],&no[6],&no[7],&no[8],&no[9],&no[10],&no[11],&no[12]);
        /*for (i=0;i<13;i++){
            printf("%d ",no[i]);
        }*/
        if(i<(y-2000))
        {
            for (j=1;j<13;j++)
            {
                sum += no[j];
            }
        }
        else
        {
            for(j=1;j<m;j++)
            {
                sum += no[j];
            }
        }

        ch=fgetc(fptr);
        if(ch=='\n')
            i++;
    }

    return (sum+d);
}
