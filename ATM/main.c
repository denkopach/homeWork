#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int pinAndMoney[5000][2];
    int i, j;
    int adminPin = 0; //here we specify the admin password

    for (i = 0, j = 1; i < 5000; i++, j += 2){
        pinAndMoney[i][0] = j;
        pinAndMoney[i][1] = rand()%1000;
    }

    for (;;){
        int userPin, n = 0;
        for (n = 0; n < 3; n++){
            int userPinValue, userPin;
            do {
                printf("\nEnter PIN:\n");
                userPinValue = scanf("%d", &userPin);
                fflush (stdin);
            }
            while (!userPinValue);
//admin acces
            if (userPin == adminPin){
                system ("cls");
                printf("\nHello admin!\n");
            }
            for(; userPin == adminPin;){
                    int userSelected;
                    n = 0;
                    do {
                        fflush (stdin);
                        printf("\n 1. Loock all base\n 2. reset the entire database\n 0. Exit\n");
                        userSelected = getche();
                        if (!strchr ("012", userSelected)){
                            printf("\nInvalid value\n");
                        }
                    }
                    while (!strchr ("012", userSelected));

                        if (userSelected == '1'){
                            int i, j;
                            for (i = 0; i < 5000; i++){
                                for(j = 0; j < 2; j++){
                                    printf("%d ", pinAndMoney[i][j]);
                                }
                                printf("\n");
                            }
                        }

                        if (userSelected == '2'){
                            for (i = 0; i < 5000; i++){
                                pinAndMoney[i][1] = 0;
                            }
                            printf("\n\nAll money is nulled\n\n");
                        }

                        if (userSelected == '0'){
                            getch();
                            system("cls");
                            break;
                        }
                        if (userSelected > '2'){
                            printf("\nInvalid value!\n");
                        }
            }
            for(i = 0; i < 5000 && userPin != adminPin; i++){
                if (pinAndMoney[i][0] == userPin){
                    printf("PIN OK!!!");
                    break;
                }
            }

            if (pinAndMoney[i][0] != userPin){
                printf("Incorrect PIN");
            }
            if (n == 1){
                printf("\n\nLast try!!!\n");
                return 0;
            }
        }
        int userSelected;
        for (;userPin != 0;){
            do {
                printf("\nPlease select an operation\n 1. Take money\n 2. Put money\n 3. Check balance\n 0. Exit\n");
                printf("Please select an operation (0-3): ");
                userSelected = getche();
                if (!strchr ("0123", userSelected)){
                    printf("\nInvalid value\n");
                }
            }
            while (!strchr ("0123", userSelected));

            //process operation "Take Money"
            if (userSelected == '1'){
                int selectedMoney, selectedMoneyValue = 0;
                do {
                    printf("\nHow much money you want take?: (max = %d)", pinAndMoney[i][1]);
                    selectedMoneyValue = scanf(" %d", &selectedMoney);
                    fflush (stdin);
                    if (!selectedMoneyValue) {
                        printf("\nYou input inkorreck value!\n");
                    }
                    else if (selectedMoney > pinAndMoney[i][1]){
                        printf("\nYour balance is short of funds!!!\n");
                    }
                }
                while (!selectedMoneyValue || selectedMoney > pinAndMoney[i][1]);
                pinAndMoney[i][1] = pinAndMoney[i][1] - selectedMoney;
                system ("cls");
            }

            //Process operation "Put money"
            if (userSelected == '2'){
                int selectedMoney, selectedMoneyValue = 0;
                do {
                    printf("\nHow much money you want put?: ", pinAndMoney[i][1]);
                    selectedMoneyValue = scanf(" %d", &selectedMoney);
                    fflush (stdin);
                    if (!selectedMoneyValue) {
                        printf("\nYou input inkorreck value!\n");
                    }
                }
                while (!selectedMoneyValue);
                pinAndMoney[i][1] = pinAndMoney[i][1] + selectedMoney;
                system ("cls");
            }
            if (userSelected == '3'){
                printf("\n\nYour ballance is: %d\n", pinAndMoney[i][1]);
            }
            if (userSelected == '0'){
                system ("cls");
                break;
            }
        }
    }
}
