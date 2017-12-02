#include <iostream>

using namespace std;

class Stack{
private:
    const int SIZE_QUEUE = 10;
    int* queueArray = new int[SIZE_QUEUE];
    int* last;
    bool full;

public:
    Stack(){
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

    bool isFull(){
        return last == &queueArray[10];
    }
    bool isVoid(){
        return last == queueArray;
    }
};

int main()
{
    Stack s;
    for (int i = 0; i < 11; i++){
        s.put(i);
    }
    for (int i =0; i < 11; i++){
        cout<<s.get()<<endl;
    }
}
