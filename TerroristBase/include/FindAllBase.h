#ifndef FINDALLBASE_H
#define FINDALLBASE_H
#include "CreateData.h"

class FindAllBase{
private:
    const char SAND = '.';
    const static int MAX_SIZE_BASE = 20;
    const static int MAX_SIZE_PLACE = 100;
    CreateData* data;
public:

    FindAllBase(CreateData*);
    int findBase();
    bool checkFirstSymbol(char*, char*);
    bool checkPlacePresenceBase(char**, char**, int, int, int, int);
    bool checkSymbol(char, char);
    virtual ~FindAllBase();
};

#endif // FINDALLBASE_H
