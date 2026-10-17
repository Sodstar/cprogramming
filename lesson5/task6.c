#include<stdio.h>

void bodlogo1(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ", i);
    }
}

void bodlogo2(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d ", i);
        if(i%2==0)
            printf("tegsh\n");
        else
            printf("sondgoi\n");
    }
}

void bodlogo3(int n)
{
    int i,sum=0,s=1;
    for(i=1;i<=n;i++)
    {
       sum=sum+i;
       s=s*i;
    }
    printf("Sum: %d\n", sum);
    printf("S: %d\n", s);
}

double find_max(int n)
{
    int i;
    double a, max;
    for(i=1;i<=n;i++)
    {
        scanf("%lf", &a);
        if(i==1) max=a;
        if(a>max)
            max=a;
    }
    return max;
}


int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    bodlogo1(n);
    bodlogo2(n);
    bodlogo3(n);
    printf("Max:%lf\n", find_max(n));
}