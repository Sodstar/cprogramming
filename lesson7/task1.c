#include<stdio.h>
int main()
{
    printf("Oyutnii dungiin dundaj\n");
    int i, n,sum=0,gar,max,min;
    printf("n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        printf("Oyutan %d: ", i);
        scanf("%d", &gar);
        if(i==1)
        {
            max=gar;
            min=gar;
        }
        sum+=gar;
        if(gar>max)
            max=gar;
        if(gar<min)
            min=gar;
    }
    printf("Avg: %d\n",sum/n);
    printf("Max: %d\n",max);
    printf("Min: %d\n",min);
}