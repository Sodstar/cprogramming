///* N тоо гараас өгнө. N удаа гараас A хувьсагчид утга аваад хамгийн ихийг ол. */
#include<stdio.h>
int main()
{
    int n, c=1;
    double a, max=0;

    printf("n: ");
    scanf("%d",&n);
    scanf("%lf", &a);
    max=a;
    while(c<n) //n>=c  c<=n 
    {
        scanf("%lf", &a);
        if(a>max)
            max=a;
        c++; //c=c+1;
    }
    printf("Max: %lf\n", max);

}
