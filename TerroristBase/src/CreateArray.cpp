#include "CreateArray.h"

CreateArray :: CreateArray (int n){
    createArray = new char*[n];
    for(int i = 0; i < n; i++){
        createArray[i] = new char[n];
    }
}
char** CreateArray :: returnArray(){
        return createArray;
}

