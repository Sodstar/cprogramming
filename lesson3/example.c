#include<stdio.h>
int main()
{
    printf("*****Tic Tac Toy*****\n");

    int menu=0;
    printf("1. Main menu\n");
    printf("2. Single player\n");
    printf("3. 2 players\n");
    printf("4. Exit\n");

    while(menu!=4)
    {
        printf("Choose your option: ");
        scanf("%d",&menu);

        if(menu==1)
        {
            int age;
            printf("*****Main menu*****\n");
            printf("Enter your age?: ");
            scanf("%d",&age);
        }
        else if(menu==2)
        {
            int age;
            printf("*****Single Player*****\n");
            printf("Enter your age?: ");
            scanf("%d",&age);
        }
        else if(menu==3)
        {
            int age1,age2;
            printf("*****Single Player*****\n");
            printf("Enter your age [Player 1]?: ");
            scanf("%d",&age1);
            printf("Enter your age [Player 2]?: ");
            scanf("%d",&age2);
        }
        else if(menu==4)
        {
            printf("Exited\n");
        }
        else
            printf("Wrong option\n");

    }
}