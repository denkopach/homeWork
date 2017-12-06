#include "Base.h"

char** Base :: createBase(std::ifstream *input){
    base = CreateArray (MAX_SIZE_BASE).returnArray();
    *input >> baseSizeN >> baseSizeM;
    for(int i = 0; i < baseSizeN; i++){
        *input >> base[i];
    }

    return base;
}

