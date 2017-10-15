#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(;;){
        int userMonnet = 0;
        int userMonnetValue = scanf("%d", &userMonnet);;
        for (; userMonnetValue == 0;){
            fflush (stdin);
            printf("Pls enter number ");
            userMonnetValue = scanf("%d", &userMonnet);
        }
        char monnet[6] = {50, 25, 10, 5, 2, 1};
        int i = 0;
        int numberOfCoins = 0;
        for (i = 0; i < 6; i++){
                printf("coin %d - %d pieces\;\n", monnet[i], userMonnet / monnet[i]);
                numberOfCoins = numberOfCoins + userMonnet / monnet[i];
                userMonnet = userMonnet % monnet[i];
        }
        printf("number of coins = %d", numberOfCoins);
    }
}
