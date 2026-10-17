/* 1->n тоог While давталтаар хэвлэнэ гэхдээ дараах байдлаар харуулна */
#include<stdio.h>
int main()
{
    int n, c=1;
    printf("n: ");
    scanf("%d",&n);

    while(c<=n) //n>=c  c<=n 
    {
        printf("%d ", c);
        if(c%2==0)
            printf("tegsh");
        else
            printf("sondgoi");
        printf("\n");
        c++; //c=c+1;
    }
}
