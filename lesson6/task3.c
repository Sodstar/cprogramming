#include<stdio.h>
#define RATE 3450.0

float maxy(float a, float b, float c, float d)
{
    float max;
    max=a;
    if(b>max)
        max=b;
    if(c>max)
        max=c;
    if(d>max)
        max=d;
    return RATE;
}

void max_print(float a, float b, float c, float d)
{
    float max;
    max=a;
    if(b>max)
        max=b;
    if(c>max)
        max=c;
    if(d>max)
        max=d;
    printf("Max: %f\n",max);
}

int main()
{
   printf("Max: %f\n",maxy(1,3,5,5));
   max_print(2,4,4.01,4);
   max_print(3,2,4.01,1);
   max_print(2,3,1,1);
   max_print(4,4,4.01,1);
   max_print(1,4,5,1);
   max_print(2,4,8.01,1);
   char temdegt='A';

printf("%c",temdegt);
}