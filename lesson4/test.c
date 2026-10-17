#include<stdio.h>
int main()
{
    int counter=1, n;
    int niilber=0, urjver=1;
    printf("N: ");
    scanf("%d",&n);
    while(counter<=n)
    {
        niilber=niilber+counter;
        urjver=urjver*counter;

        counter=counter+1;
    }
    printf("Niilber: %d\n" , niilber);
    printf("Urjver: %d\n" , urjver);
}