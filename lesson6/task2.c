#include<stdio.h>
#include<math.h>

int kvadrat_zereg(int k, double m)
{
    return pow(k,m);
}

int main()
{
    int x;
    for(x=1;x<=10;x++)
    {
        printf("%d ",kvadrat_zereg(x,x+1));
    }
}