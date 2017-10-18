#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int pinAndMoney[5000][2];
int i, j;
int getNumeral(void);
int getInt(void);

void PrintMassive(void);
void CreateBaseUser(void);
void AdminAccess(void);
int adminPin = 0;

int main()
{
    CreateBaseUser();
    for (;;){
        int userPin,n = 0;
        for (n = 0; n < 3; n++){
            bool pinOk = false;
            int userPinValue;
            userPin = getInt();
            if (userPin == adminPin){
                AdminAccess();
                break;
            }
            for(i = 0; i < 5000; i++){
                if (pinAndMoney[i][0] == userPin){
                    printf("PIN OK!!!");
                    pinOk = true;
                    break;
                }
            }
            if (pinAndMoney[i][0] == userPin){
                break;
            }
            if (n == 0){
                printf("Incorrect PIN");
                printf("\n\nYou have 2 try!\n");
            }
            if (n == 1){
                printf("Incorrect PIN");
                printf("\n\nLast try!!!\n");
            }
            if (n == 2){
                return 0;
            }
        }
        int userSelected;
        for (;userPin != 0;){
            do {
                printf("\nFor PIN %d, you can:\n 1. Take money\n 2. Put money\n 3. Check balance\n 0. Exit\n", userPin);
                printf("Please select an operation (0-3): ");
                userSelected = getche();
            // printf("%d", userSelected);
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
//Print massive
void PrintMassive (void)
{
    int i, j;
     for (i = 0; i < 5000; i++){

        for(j = 0; j < 2; j++){
            printf("%d ", pinAndMoney[i][j]);
        }
        printf("\n");
    }
}
// create massive with PIN and monney
void CreateBaseUser(void){
    for (i = 0, j = 1; i < 5000; i++, j += 2){
        pinAndMoney[i][0] = j;
        pinAndMoney[i][1] = rand()%1000;
    }
}
//admin acñess
void AdminAccess(void){
    system ("cls");
    printf("\nHello admin!\n");
    for(;;){
            printf("\n 1. Loock all base\n 2. reset the entire database\n 0. Exit\n");
            int userSelected = getNumeral();

            if (userSelected == 1){
                PrintMassive();
            }

            if (userSelected == 2){
                for (i = 0; i < 5000; i++){
                    pinAndMoney[i][1] = 0;
                }
            }

            if (userSelected == 0){
                system("cls");
                break;
            }
            if (userSelected > 2){
                printf("\nInvalid value!\n");
            }
    }
}
//get a number from 0 to 9
int getNumeral(){
    int userEnterValue;
    do {
        userEnterValue = getche();
        fflush (stdin);
        if (!strchr ("0123", userEnterValue)){
            printf("\nInvalid value\n");
        }
    }
    while (!strchr ("0123456789", userEnterValue));
    return userEnterValue-48;
}
//get demical number
int getInt(){
    int userPinValue, userPin;
    do {
        printf("\nEnter PIN:\n");
        userPinValue = scanf("%d", &userPin);
        fflush (stdin);
    }
    while (!userPinValue);
    return userPin;
}
