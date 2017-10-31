#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getString(int);
int getNumberOfWords(char*);

int main()
{
    for (;;){
        char messageForUser[100] = "\nEnter text:\n";
        char *textString = getString(messageForUser);
        printf("Words - %d", getNumberOfWords(textString));
        free(textString);
    }
}
int getString(int messageForUser)
{
    if (!strlen(messageForUser)){
        printf("\nError! messageForUser is empty\n");
    }
    const int STRING_SIZE = 10000; //the maximum size of the text to be typed
    char *textString = (char*)malloc(STRING_SIZE * sizeof(char)); //Allocating memory
    printf("%s", messageForUser);
    char* tempVar = gets(textString);
    fflush (stdin);
    return textString;
}
int getNumberOfWords(char* textString){
    int i, j = 0;
    const int SIZE_ALPHABET = 26;
    const int ASCII_NUMBER_SMAL_A = 97;
    const int TRUE = 1;
    const int FALSE = 0;
    int numberOfWords = 0;
    int trueLetter = FALSE;
    int trueSymbol = FALSE;

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
    return numberOfWords;
}
