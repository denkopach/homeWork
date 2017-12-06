#include "CreateData.h"

CreateData :: CreateData(char* fileName){
    std::ifstream input(fileName);
    if (!input){
        std::cout <<std::endl<<" ERROR! File "<<fileName<<" not exist";
        exit(1);
    }
    baseArr = base.createBase(&input);
    placeArr = place.createPlace(&input);
    input.close();
}
