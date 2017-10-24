#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


int main()
{
    for (;;){

        const int STRING_SIZE = 10000; //the maximum size of the text to be typed
        const int SIZE_ALPHABET = 26;
        const int NUMBER_OF_COLUMNS = 2;
        const int COLUMN_WITH_LETTER = 0;
        const int COLUMN_WITH_LETTER_AMOUNT = 1;
        const int ASCII_NOMBER_BIG_A = 65;
        const int ASCII_NOMBER_SMAL_A = 97;

        char letterAndAmountArray [SIZE_ALPHABET][NUMBER_OF_COLUMNS];
        char *tempVar; //temporary variable for text input
//        char textString [STRING_SIZE];

        char *textString;
        textString = (char*)malloc(STRING_SIZE * sizeof(char));
        int i,j = 0; //variables for counters
        int sizeFilledArr = 0;//the size of the filled array
        int tempSort = 0; //temporary variable for sorting

        //zeroing an array
        for (i = 0; i < SIZE_ALPHABET; i++){
            for(j = 0; j < NUMBER_OF_COLUMNS; j++){
                letterAndAmountArray[i][j] = 0;
           }
        }

        printf("\nEnter text:\n");
        tempVar = gets(textString);
        fflush (stdin);

        int amountLetter = 1; //Counting starts from one

        //counting of letters
        for(i = 0; i < SIZE_ALPHABET; i++){
            for(j = 0; j < strlen(textString); j++){

                if (textString[j] == i + ASCII_NOMBER_BIG_A || textString[j] == i + ASCII_NOMBER_SMAL_A){
                    letterAndAmountArray[sizeFilledArr][COLUMN_WITH_LETTER] = i + ASCII_NOMBER_BIG_A;
                    letterAndAmountArray[sizeFilledArr][1] = amountLetter;
                    amountLetter++;
                }
            }
            if (amountLetter > 1){
                sizeFilledArr++;
            }
            amountLetter = 1;
        }

        //sort an array from large to small
        for (j = 0; j < sizeFilledArr; j++){
            for (i = 0; i <= sizeFilledArr; i++){
                if (letterAndAmountArray[i][COLUMN_WITH_LETTER_AMOUNT] < letterAndAmountArray[i+1][COLUMN_WITH_LETTER_AMOUNT]){
                    tempSort = letterAndAmountArray[i+1][COLUMN_WITH_LETTER];
                    letterAndAmountArray[i+1][COLUMN_WITH_LETTER] = letterAndAmountArray[i][COLUMN_WITH_LETTER];
                    letterAndAmountArray[i][COLUMN_WITH_LETTER] = tempSort;
                    tempSort = letterAndAmountArray[i+1][COLUMN_WITH_LETTER_AMOUNT];
                    letterAndAmountArray[i+1][COLUMN_WITH_LETTER_AMOUNT] = letterAndAmountArray[i][COLUMN_WITH_LETTER_AMOUNT];
                    letterAndAmountArray[i][COLUMN_WITH_LETTER_AMOUNT] = tempSort;
                }
            }
        }

        //array output
        for(i = 0; i < sizeFilledArr; i++){
            printf("%c - %d\n", letterAndAmountArray[i][COLUMN_WITH_LETTER], letterAndAmountArray[i][COLUMN_WITH_LETTER_AMOUNT]);
        }
    }
}
