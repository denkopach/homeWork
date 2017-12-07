#include <iostream>
#include <cstring>
#include "CreateData.h"
#include "FindAllBase.h"
#include "Test.h"

using namespace std;

int main(int argc, char* argv[]){

    //Test execution if the argument is "--test", otherwise the program runs
    if(argc > 1 && !strcmp(argv[1],"--test")){
        Test();
    }else{
        CreateData data("C:/lessons/homework/TerroristBase/input.txt");
        cout<<FindAllBase(&data).findBase();
    }

    return 0;
}
