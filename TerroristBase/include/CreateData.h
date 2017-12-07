#ifndef CREATEDATA_H
#define CREATEDATA_H
#include <iostream>
#include <stdlib.h>
#include "Base.h"
#include "Place.h"

class CreateData{
private:
    int placeSizeN, placeSizeM;
    int baseSizeN, baseSizeM;
public:
    char** baseArr;
    char** placeArr;
    Base base;
    Place place;
    CreateData(char*);
    virtual ~CreateData();
};

#endif // CREATEDATA_H
