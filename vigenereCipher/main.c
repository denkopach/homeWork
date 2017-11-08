#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

const int SIZE_STR = 1000000; //the size of the input string
const int SIZE_ALPHABET = 26;

char* getsString(char messageForUser[]){
    printf("%s", messageForUser);
    char* str = (char*)malloc(SIZE_STR * sizeof(char));
    fflush (stdin);
    char tmpStr = gets(str);
    return str;
}

int checkArg(int argc, char** argv ){
    if (argc <= 1){
        printf("to run the program, you must enter argument (\"-d\" for decryption, \"-e\" for encryption)");
        return 1;
    }
    if (!strcmp (argv[1], "-e") || !strcmp (argv[1], "-d")){
        return 0;
    }
    else {
        printf("to run the program, you must enter one argument (\"-d\" for decryption, \"-e\" for encryption)");
        return 1;
    }
}

char* getEncryption(char* string, char* keyForCipher){
    char* codedSrting = (char*)malloc(SIZE_STR * sizeof(char));
    int i, j;
    for(i = 0, j = 0; i < strlen(string); i++, j++){
        if (j == strlen(keyForCipher )){
            j = 0;
        }
        if (isalpha(string[i])){
            codedSrting[i] = (string[i] + keyForCipher[j] - 2*'a') % SIZE_ALPHABET + 'a';
        }
    }
    return codedSrting;
}

char* getDecryption(char* string, char* keyForCipher){
    char* codedSrting = (char*)malloc(SIZE_STR * sizeof(char));
    int i, j;
    for(i = 0, j = 0; i < strlen(string); i++, j++){
        if (j == strlen(keyForCipher )){
            j = 0;
        }
        if (isalpha(string[i])){
            codedSrting[i] = (string[i] - keyForCipher[j] + SIZE_ALPHABET) % SIZE_ALPHABET + 'a';
        }
    }
    return codedSrting;
}

 int main(int argc, char **argv) {
    if (checkArg(argc, argv)){
        return 0;
    }
    char* keyForCipher = getsString("\nEnter key:");
    char* string = getsString("\nEnter text:");
    char* codedSrting = NULL;

    if (!strcmp (argv[1], "-e")){
        codedSrting = getEncryption(string, keyForCipher);
    }
    if (!strcmp (argv[1], "-d")){
        codedSrting = getDecryption(string, keyForCipher);
    }
    else{
        return 1;
    }
    printf("\n%s", codedSrting);

    free(string);
    free(keyForCipher);
    free(codedSrting);

    return 0;
}
