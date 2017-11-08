#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


const int SIZE_STR = 1000000; //the size of the input string
const int SIZE_ALPHABET = 26;
//receiving a key for encryption, it can consist only of digits
int getKeyForCipher(){
    int keyForCipher, tmpN = 0;
    do {
        printf("Enter key for cipher (only numbers): ");
        fflush (stdin);
        tmpN = scanf("%d", &keyForCipher);
    }while (!tmpN);
    return keyForCipher;
}

char* getsString(){
    printf("Enter text: ");
    char* str = (char*)malloc(SIZE_STR * sizeof(char));
    fflush (stdin);
    char tmpStr = gets(str);
    return str;
}

void encryption(char* string, int keyForCipher){
    int i;

    for(i = 0; i < strlen(string); i++){
        if (isalpha(string[i]) && keyForCipher > SIZE_ALPHABET){
            string[i] = string[i] + keyForCipher % SIZE_ALPHABET;
        }
        if (isalpha(string[i]) && keyForCipher <= SIZE_ALPHABET){
            string[i] = string[i] + keyForCipher;
        }
    }
}

void decoder(char* string, int keyForCipher){
    int i;
    for(i = 0; i < strlen(string); i++){
        if (isalpha(string[i]) && keyForCipher > SIZE_ALPHABET){
            string[i] = string[i] - keyForCipher % SIZE_ALPHABET;
        }
        if (isalpha(string[i]) && keyForCipher <= SIZE_ALPHABET){
            string[i] = string[i] - keyForCipher;
        }
    }
}

int checkArg(int argc, char** argv ){
    if (argc <= 1){
        printf("to run the program, you must enter one argument (\"-d\" for decryption, \"-e\" for encryption)");
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

void stringOperation(char* string, char** argv, int keyForCipher){
    if (!strcmp (argv[1], "-e")){
        encryption(string, keyForCipher);
    }
    if (!strcmp (argv[1], "-d")){
        decoder(string, keyForCipher);
    }
}

 int main(int argc, char **argv) {

    if (checkArg(argc, argv)){
        return 0;
    }
    int keyForCipher = getKeyForCipher();
    char* string = getsString();
    stringOperation(string, argv, keyForCipher);
    printf("\n%s", string);

    return 0;
}
