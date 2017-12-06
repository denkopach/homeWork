#include "Test.h"

Test :: Test() {
    testArr = createTestData();
    for(int i = 0; i < 6; i++){
        std::cout<<"Test "<<i+1<<" - ";
        if(checkResult(getResult(testArr[i]), i) == mapAnsver[i]){
            std::cout<<"test passed"<<std::endl;
        }else{
            std::cout<<"test failed"<<std::endl;
        }
    }
}

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
    CreateData data(fileQuest);
    return FindAllBase(&data).findBase();
}

bool Test :: checkResult(int n, int i){
    return resultTable[i] == n;
}
