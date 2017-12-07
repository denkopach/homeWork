#include "FindAllBase.h"
/**
*   class counts the number of occurrences of an array with a base in an array with a place
*/

FindAllBase :: FindAllBase(CreateData* data){
    this->data = data;
}

int FindAllBase :: findBase(){
    int count = 0;
    for(int i = 0; i <= data->place.placeSizeN - data->base.baseSizeN; i++){
        for(int j = 0; j <= data->place.placeSizeM - data->base.baseSizeM; j++){
             if (checkFirstSymbol(&data->baseArr[0][0], &data->placeArr[i][j])){
                if (checkPlacePresenceBase(data->baseArr, data->placeArr, i, j, data->base.baseSizeN, data->base.baseSizeM)){
                    count++;
                }
            }
        }
    }

    return count;
}

bool FindAllBase :: checkFirstSymbol(char* baseEllement, char* placeEllement){
    return (*baseEllement == *placeEllement || *baseEllement == SAND);
}

bool FindAllBase :: checkPlacePresenceBase(char* base[MAX_SIZE_BASE], char* place[MAX_SIZE_PLACE], int i, int j, int nBase, int mBase){
    bool isTrue = true;
    for(int x = 0; x < nBase; x++){
        for(int y = 0; y < mBase; y++){
            if (checkSymbol(base[x][y], place[i+x][j+y])){
                return false;
            }
        }
    }

    return true;
}

bool FindAllBase :: checkSymbol(char baseEllement, char placeEllement){
    return (baseEllement != placeEllement && baseEllement != SAND);
}
FindAllBase :: ~FindAllBase(){

}
