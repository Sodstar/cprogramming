#include<stdio.h>
int main()
{
    int c=1,d;
    while(c<=8)
    {
        d=1;
        while(d<=8)
        {
            if(c==2 && d==3)
                printf(" K ");
            else
                printf(" * ");
            d++;
        }
        printf("\n");
        c++;
    }
}