#include<stdio.h>
int main()
{
    int i,n,sum, max, min;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    max=a[0];
    min=a[0];
    sum=a[0];
    for(i=1;i<n;i++)
    {
        sum=sum+a[i];
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    printf("Avg: %d\n",sum/n);
    printf("Max: %d\n",max);
    printf("Min: %d\n",min);
    for(i=n-1;i>=0;i--)
    {
          printf("%d ",a[i]);
    }

}