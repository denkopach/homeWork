#ifndef BASE_H
#define BASE_H
#include <fstream>
#include "CreateArray.h"

class Base{
public:
    const int MAX_SIZE_BASE = 20;
    const int MAX_SIZE_PLACE = 100;
    const char SAND = '.'; //a symbol of sand
    int baseSizeN, baseSizeM;
    char** base;
    char** createBase(std::ifstream *);
};

#endif // BASE_H
