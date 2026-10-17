#include<stdio.h>
int main()
{
    printf("Plane Game V1.0\n");
    int i,j;
    int m,n;
    int sum=0;
    int max;
    printf("m: ");
    scanf("%d",&m);
    printf("n: ");
    scanf("%d",&n);
    int board[m][n];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &board[i][j]);
            sum=sum+board[i][j];
        }
    }

    max=board[0][0];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=0 && j!=0)
            {
                if(board[i][j]>max)
                    max=board[i][j];
            }
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    
    printf("\n---------------------Sum: %d\n",sum);
    printf("\n---------------------Max: %d\n",max);
}