#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

const SIZE_STR = 1000;
const int SIZE_ARRAY = 26;
int i, j = 0;

char* getsString(){
    printf("Enter text: ");
    char* str = (char*)malloc(SIZE_STR * sizeof(char));
    char tmpStr= gets(str);
    return str;
}

int* createArray (int size){
    int* array = (int*)malloc(size * sizeof(int));
    int i = 0;
    for(i = 0; i < size; i++){
        array[i] = 0;
    }
    return array;
}

void countingOfLetters(char* string, char* letterArray, int* amountArray){
    int tmpQuantity = 0;
    for(i = 0; i < strlen(string); i++){
        for (j = 0; j < SIZE_ARRAY; j++){
            if (!isalpha(string[i])){
                break;
            }
            if (i == 0){
                letterArray[tmpQuantity] = string[i];
                amountArray[tmpQuantity] = 1;
                tmpQuantity++;
                break;
            }
            if (letterArray[j] == string[i]){
                amountArray[j]++;
                break;
            }
            if (j == SIZE_ARRAY-1) {
                letterArray[tmpQuantity] = string[i];
                amountArray[tmpQuantity]++;
                tmpQuantity++;
            }
        }
    }
}

void printResult (char* letterArray, int* amountArray){
    for (i = 0; i < SIZE_ARRAY; i++){
        if (amountArray[i] > 0){
                printf("%c - %d\n",letterArray[i], amountArray[i]);
        }
    }
}

void swapInt(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swapChar(char *xp, char *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortingArray (char* arrChar, int* arrInt){
    for ( i = 0; i < SIZE_ARRAY-1; i ++ ){
        for ( j = SIZE_ARRAY-2; j >= i; j -- ){
            if ( arrInt[j] < arrInt[j+1] ){
                swapInt(&arrInt[j], &arrInt[j+1]);
                swapChar(&arrChar[j], &arrChar[j+1]);
            }
        }
    }
}

int main()
{
    char* letterArray = createArray(SIZE_ARRAY);
    int* amountArray = createArray(SIZE_ARRAY);
    char* string = getsString();
    countingOfLetters(string, letterArray, amountArray);
    sortingArray (letterArray, amountArray);
    printResult(letterArray, amountArray);
    getch();
}
