#ifndef TEST_H
#define TEST_H
#include "CreateData.h"
#include <iostream>
#include "FindAllBase.h"

class Test{
private:
    const static int NUMBER_TEST = 6;
    int resultTable[NUMBER_TEST] = {4, 6, 4, 2, 5, 8};;
    char** testArr = new char*[NUMBER_TEST];
    int mapAnsver[NUMBER_TEST] = {true, true, true, false, false, true};
public:
    Test();
    char** createTestData();
    int getResult(char*);
    bool checkResult(int, int);
    virtual ~Test();
};

#endif // TEST_H
