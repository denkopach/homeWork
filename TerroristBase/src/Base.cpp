#include "Base.h"
/**
*   create an array with the base plan
*/
char** Base :: createBase(std::ifstream *input){
    base = CreateArray (MAX_SIZE_BASE).returnArray();
    *input >> baseSizeN >> baseSizeM;
    for(int i = 0; i < baseSizeN; i++){
        *input >> base[i];
    }
    return base;
}

Base :: ~Base(){
    delete base;
}
