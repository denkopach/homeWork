#ifndef FINDALLBASE_H
#define FINDALLBASE_H
#include "CreateData.h"
    const char SAND = '.';
    const int MAX_SIZE_BASE = 20;
    const int MAX_SIZE_PLACE = 100;
    class FindAllBase{
private:
    CreateData* data;

public:

    FindAllBase(CreateData*);
    int findBase();
    bool checkFirstSymbol(char*, char*);
    bool checkPlacePresenceBase(char**, char**, int, int, int, int);
    bool checkSymbol(char, char);
    ~FindAllBase(){
    }
};

#endif // FINDALLBASE_H
