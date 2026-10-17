///* N тоо гараас өгнө. 1-N хүртлэх тооны нийлбэр, үржвэрийг ол. */
#include<stdio.h>
int main()
{
    int n, c=1;
    float sum=0, s=1;

    printf("n: ");
    scanf("%d",&n);

    while(c<=n) //n>=c  c<=n 
    {
        sum=sum+c;
        s=s*c;
        c++; //c=c+1;
    }

    printf("Sum: %.2f\n",sum);
    printf("S: %.2f\n", s);
}
