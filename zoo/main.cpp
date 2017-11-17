/**
 *   Created by Den Kopach 17.11.2017
*/
#include <iostream>
#include <stdlib.h>
#include "include/Interface.h"

using namespace std;

int main()
{
    //fill the database
    arrayPointers->add(new Animals ("cat", 5, 4, "nice"));
    arrayPointers->add(new Animals ("dog", 7, 4, "sdfs"));
    arrayPointers->add(new Animals ("pig", 5, 4, "nisdfsdfce"));
    arrayPointers->add(new Animals ("bird", 5, 4, "gaga"));

    //all functions are launched from the class Interface
    Interface* interface;

    for (;;){
        interface->mainMenu();
    }
}
