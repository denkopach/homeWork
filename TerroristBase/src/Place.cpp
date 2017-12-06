#include "Place.h"

char** Place :: createPlace(std::ifstream* input){
    place = CreateArray (MAX_SIZE_PLACE).returnArray();
    *input >> placeSizeN >> placeSizeM;
    for(int i = 0; i < placeSizeN; i++){
        *input >> place[i];
    }

    return place;
}
