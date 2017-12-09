#include <iostream>

using namespace std;

class Stack{
private:
    const int SIZE_QUEUE = 10;
    int* queueArray;
    int* last;
    bool full;

public:
    Stack(){
        queueArray = new int[SIZE_QUEUE];
        last = queueArray;
    }

    void put(int data){
        if(isFull()){
            cout<<"Error - Queue is full"<<endl;
            return;
        }
        *last = data;
        last++;
    }

    int get(){
        if(isVoid()){
            cout<<"Error - Queue is empty"<<endl;
            return 0;
        }
        int data = *(last-1);
        if (!isVoid()){
            last--;
        }
        return data;
    }

    //check for fullness
    bool isFull(){
        return last == &queueArray[10];
    }

    //check for emptiness
    bool isVoid(){
        return last == queueArray;
    }

    ~Stack(){
        delete []queueArray;
    }
};

int main()
{
    Stack s;
    for (int i = 0; i < 12; i++){
        s.put(i);
    }
    for (int i =0; i < 12; i++){
        cout<<s.get()<<endl;
    }
}
