#ifndef CREATEDATA_H
#define CREATEDATA_H
#include <iostream>
#include <stdlib.h>
#include "Base.h"
#include "Place.h"

class CreateData{
public:
    int placeSizeN, placeSizeM;
    int baseSizeN, baseSizeM;
    char** baseArr;
    char** placeArr;
    Base base;
    Place place;

    CreateData(char*);
};

#endif // CREATEDATA_H
