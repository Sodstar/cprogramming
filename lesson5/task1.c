/* 1->n тоог While давталтаар хэвлэх */

#include<stdio.h>

int main()
{
    int n, c=1;
    printf("n: ");
    scanf("%d",&n);

    while(c<=n) //n>=c  c<=n 
    {
        printf("%d\n", c);
        c=c+1; //c++
    }
}
