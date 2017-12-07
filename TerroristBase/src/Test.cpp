#include "Test.h"
/**
*   The class tests the operation of the program and compares the result with the expected
*/

Test :: Test() {
    testArr = createTestData();
    //check the results on the map
    for(int i = 0; i < 6; i++){
        std::cout<<"Test "<<i+1<<" - ";
        if(checkResult(getResult(testArr[i]), i) == mapAnsver[i]){
            std::cout<<"test passed"<<std::endl;
        }else{
            std::cout<<"test failed"<<std::endl;
        }
    }
}

//create an array with the addresses of the files containing the incoming data for the program
char** Test :: createTestData(){

    for(int i = 0; i < NUMBER_TEST; i++){
        testArr[i] = new char;
    }
    testArr[0] = "C:/lessons/homework/TerroristBase/test1.txt";
    testArr[1] = "C:/lessons/homework/TerroristBase/test2.txt";
    testArr[2] = "C:/lessons/homework/TerroristBase/test3.txt";
    testArr[3] = "C:/lessons/homework/TerroristBase/test4.txt";
    testArr[4] = "C:/lessons/homework/TerroristBase/test5.txt";
    testArr[5] = "C:/lessons/homework/TerroristBase/test6.txt";
    return testArr;
}

int Test :: getResult(char* fileQuest){
    //we get the result of the program
    CreateData data(fileQuest);
    return FindAllBase(&data).findBase();
}

bool Test :: checkResult(int n, int i){
    //We check the result of the program with the expected result
    return resultTable[i] == n;
}

Test :: ~Test() {
    //free the allocated memory
    for(int i = 0; i < NUMBER_TEST; i++){
        delete testArr[i];
    }
}
