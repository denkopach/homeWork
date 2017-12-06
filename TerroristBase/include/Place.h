#ifndef PLACE_H
#define PLACE_H
#include <fstream>
#include "CreateArray.h"

class Place{
public:
    const int MAX_SIZE_BASE = 20;
    const int MAX_SIZE_PLACE = 100;
    const char SAND = '.'; //a symbol of sand
    int placeSizeN, placeSizeM;
    char** place;
    char** createPlace(std::ifstream *);
};

#endif // PLACE_H
