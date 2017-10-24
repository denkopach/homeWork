#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    for (;;){
        const int SIZE_ALPHABET = 26;
        const int ASCII_NUMBER_SMAL_A = 97;
        const int TRUE = 1;
        const int FALSE = 0;
        const int STRING_SIZE = 10000; //the maximum size of the text to be typed

        char *textString; //array pointer
        textString = (char*)malloc(STRING_SIZE * sizeof(char)); //Allocating memory

        int numberOfWords = 0;
        char *tempVar; //temporary variable for text input

        int trueLetter = FALSE;
        int trueSymbol = FALSE;

        printf("\nEnter text:\n");
        tempVar = gets(textString);
        fflush (stdin);

        int i, j = 0;

        for (i = 0; i < strlen(textString); i++){
            for (j = 0; j < SIZE_ALPHABET; j++){
                if (textString[i] == j + ASCII_NUMBER_SMAL_A){
                    trueSymbol = FALSE;
                    trueLetter = TRUE;
                    break;
                }
                else {
                    trueSymbol = TRUE;
                }
            }
            if(i != 0 && trueSymbol || i + 1 == strlen(textString)) {
                if (trueLetter){
                    numberOfWords++;
                    trueSymbol = FALSE;
                    trueLetter = FALSE;
                }
            }
        }
        printf("Words - %d", numberOfWords);
        free(textString);
    }
}
