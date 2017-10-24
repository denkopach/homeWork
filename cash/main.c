<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(;;){
        float floatUserMonnet = 0;
        int userMonnetValue = scanf("%f.2", &floatUserMonnet);
        int UserMonnet = floatUserMonnet*100;
        for (; userMonnetValue == 0;){
            fflush (stdin);
            printf("Pls enter number ");
            userMonnetValue = scanf("%f.2", &floatUserMonnet);
        }
        int userMonnet = floatUserMonnet * 100;
        char monnet[6] = {50, 25, 10, 5, 2, 1};
        int i = 0;
        int numberOfCoins = 0;
        for (i = 0; i < 6; i++){
                printf("coin %dfloatUserMonnet - %d pieces\;\n", monnet[i], userMonnet / monnet[i]);
                numberOfCoins = numberOfCoins + userMonnet / monnet[i];
                userMonnet = userMonnet % monnet[i];
        }
        printf("number of coins = %d", numberOfCoins);
    }
}
=======
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
>>>>>>> 359250c64ce9c9eb1587776fd42976d331b5d68a
