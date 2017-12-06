#include <iostream>
#include <cstring>
#include "CreateData.h"
#include "FindAllBase.h"
#include "Test.h"

using namespace std;

int main(int argc, char* argv[]){

    if(argc <= 1){
        CreateData data("C:/lessons/homework/TerroristBase/input.txt");
        cout<<FindAllBase(&data).findBase();
    }

    else if(!strcmp(argv[1],"--test")){
        Test();
    }

    return 0;
}
