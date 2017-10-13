#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int searchedNum = 0;
    int userNum = 0;

    for(;;){
        srand(time(NULL));
        searchedNum = rand()%10;
        printf("You have three attempts to guess the number\n");

        int i;
        for (i = 0; i < 3; i++){
            printf("Enter positive number(0-9): ");

            int userNumTemp = scanf("%d", &userNum);
            while (!userNumTemp) {
                printf("\n*EROR!* Invalid input\nEnter positive number(0-9): ");
                userNumTemp = scanf("%d", &userNum);
            }

            if(userNum < searchedNum){
                printf("\nBigger!\n\n");
            }

            if(userNum > searchedNum){
                printf("\nLower!\n\n");
            }

            if (userNum == searchedNum){
                printf("\n\n***Yahoooo! You win!***\n");
                break;
                }

            if (i == 2){
                printf("\n---You lose!!!---\n");
            }
        }
        printf("\n++++GAME OVER++++\n");

        for(;;){
            printf("\nLet's play again(y/n)? ");
            char userAnswerExit = getche();

            if (userAnswerExit == 'n')
                return 0;

            if (userAnswerExit == 'y'){
                system ("cls");
                break;
            }

            else {
                printf("\n  * Wrong answer! *\n If you want to continue play, enter \"y\". To exit, enter \"n\"");
            }
        }
    }
}
