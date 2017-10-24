#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    const int NUMBER_ACCOUNT_ARRAY = 5000; //size of the base
    const int NUMBER_COLUMN_ARRAY = 2; //number of values for one pin code
    const int NUMBER_COLUMN_MONEY = 1; //the column number in which the money is located
    const int NUMBER_COLUMN_PIN = 0; //the column number in which the PIN is located
    const char USER_CHOICE_1 = '1'; //user choice is 1
    const char USER_CHOICE_2 = '2'; //user choice is 2
    const char USER_CHOICE_3 = '3'; //user choice is 3
    const char USER_CHOICE_0 = '0'; //user choice is 0
    int pinAndMoneyArray[NUMBER_ACCOUNT_ARRAY][NUMBER_COLUMN_ARRAY]; //an array with a pin-code and money
    int i, j = 0; //variables for counters
    const int ADMIN_PIN = 0; //here we specify the admin password
    const int NUMBER_LOGIN = 3; //the number of attempts will be logged
    const char INTUT_VALIDATION_ADMIN_CHAR = '012'; //value for checking the user's choice in the admin panel
    const char INTUT_VALIDATION_USER_CHAR = '0123'; //value for checking the user's choice in the user panel
    //fill the array
    for (i = 0, j = NUMBER_COLUMN_MONEY; i < NUMBER_ACCOUNT_ARRAY; i++, j += 2){
        pinAndMoneyArray[i][NUMBER_COLUMN_PIN] = j;  //value of pin
        pinAndMoneyArray[i][NUMBER_COLUMN_MONEY] = rand()%1000; //value of money
    }

    for (;;){
        int userPin;
        int n = 0;
        //input validation
        for (n = 0; n < NUMBER_LOGIN; n++){
            int inputValidation;
            do {
                printf("\nEnter PIN:\n");
                inputValidation = scanf("%d", &userPin);
                fflush (stdin);
            }while (!inputValidation);

            //admin acces
            if (userPin == ADMIN_PIN){
                system ("cls");
                printf("\nHello admin!\n");
            }
            for(; userPin == ADMIN_PIN;){ //a loop with a test to enter the admin pin
                    int userSelected; //user choice
                    n = 0;
                    //check the correctness of the input
                    do {
                        fflush (stdin);
                        printf("\n 1. Loock all base\n 2. reset the entire database\n 0. Exit\n");
                        userSelected = getche();
                        //input validation
                        if (!strchr (&INTUT_VALIDATION_ADMIN_CHAR, userSelected)){
                            printf("\nInvalid value\n");
                        }
                    } while (userSelected != USER_CHOICE_1 && userSelected != USER_CHOICE_2 && userSelected != USER_CHOICE_0 );
                        //base output
                        if (userSelected == USER_CHOICE_1){
                            int i, j;
                            for (i = 0; i < NUMBER_ACCOUNT_ARRAY; i++){
                                for(j = 0; j < NUMBER_COLUMN_ARRAY; j++){
                                    printf("%d ", pinAndMoneyArray[i][j]);
                                }
                                printf("\n");
                            }
                        }
                        //zero the money
                        if (userSelected == USER_CHOICE_2){
                            for (i = 0; i < NUMBER_ACCOUNT_ARRAY; i++){
                                pinAndMoneyArray[i][NUMBER_COLUMN_MONEY] = 0;
                            }
                            printf("\n\nAll money is nulled\n\n");
                        }
                        //exit from the admin area
                        if (userSelected == USER_CHOICE_0){
                            system("cls");
                            break;
                        }
            }

            //We perform a search in a loop if the login is not executed under the admin
            for(i = 0; i < NUMBER_ACCOUNT_ARRAY && userPin != ADMIN_PIN; i++){
                if (pinAndMoneyArray[i][NUMBER_COLUMN_PIN] == userPin){
                        break;
                }
            }
            if (pinAndMoneyArray[i][NUMBER_COLUMN_PIN] == userPin){
                    printf("PIN OK!!!");
                    break;
            }

            if (n == NUMBER_LOGIN-2){
                printf("\n\nLast try!!!\n");
            }
            if (n == NUMBER_LOGIN-1 ){
                return 0;
            }
        }
            //execute if the pin is not true
            if (pinAndMoneyArray[i][NUMBER_COLUMN_PIN] != userPin && pinAndMoneyArray[i][NUMBER_COLUMN_PIN] != 0){
                printf("Incorrect PIN");
            }
        //login for the user
        int userSelected; //user choice
        for (;userPin != ADMIN_PIN;){
            do {
                printf("\nPlease select an operation\n 1. Take money\n 2. Put money\n 3. Check balance\n 0. Exit\n");
                printf("Please select an operation (0-3): ");
                userSelected = getche();
                if (!strchr (&INTUT_VALIDATION_USER_CHAR, userSelected)){
                    printf("\nInvalid value\n");
                }
            } while (userSelected != USER_CHOICE_1 && userSelected != USER_CHOICE_2 && userSelected != USER_CHOICE_3 && userSelected != USER_CHOICE_0);
            n = 0;
            //process operation "Take Money"
            if (userSelected == USER_CHOICE_1){
                int selectedMoney, inputValidation = 0;
                do {
                    printf("\nHow much money you want take?: (max = %d)", pinAndMoneyArray[i][NUMBER_COLUMN_MONEY]);
                    inputValidation = scanf(" %d", &selectedMoney);
                    fflush (stdin);
                    if (!inputValidation) {
                        printf("\nYou input inkorreck value!\n");
                    }
                    else if (selectedMoney > pinAndMoneyArray[i][NUMBER_COLUMN_MONEY]){
                        printf("\nYour balance is short of funds!!!\n");
                    }
                }while (!inputValidation || selectedMoney > pinAndMoneyArray[i][NUMBER_COLUMN_MONEY]);

                pinAndMoneyArray[i][NUMBER_COLUMN_MONEY] = pinAndMoneyArray[i][NUMBER_COLUMN_MONEY] - selectedMoney;
                system ("cls");
            }

            //Process operation "Put money"
            if (userSelected == USER_CHOICE_2){
                int selectedMoney, inputValidation = 0;
                do {
                    printf("\nHow much money you want put?: ", pinAndMoneyArray[i][NUMBER_COLUMN_MONEY]);
                    inputValidation = scanf(" %d", &selectedMoney);
                    fflush (stdin);
                    if (!inputValidation) {
                        printf("\nYou input incorrect value!\n");
                    }
                }while (!inputValidation);
                pinAndMoneyArray[i][NUMBER_COLUMN_MONEY] = pinAndMoneyArray[i][NUMBER_COLUMN_MONEY] + selectedMoney;
                system ("cls");
            }
            //balance check operation
            if (userSelected == USER_CHOICE_3){
                printf("\n\nYour ballance is: %d\n", pinAndMoneyArray[i][NUMBER_COLUMN_MONEY]);
            }
            //exit from the user panel
            if (userSelected == USER_CHOICE_0){
                system ("cls");
                break;
            }
        }
    }
}
