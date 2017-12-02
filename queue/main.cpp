#include <iostream>

using namespace std;

class Queue{
private:
    const int SIZE_QUEUE = 10;
    int* queueArray = new int[SIZE_QUEUE];
    int* last;
    int* first;
    bool full;

public:
    Queue(){
        first = queueArray;
        last = queueArray;
        full = false;
    }

    int* nextPtr(int* ptr){
        if(ptr == &queueArray[SIZE_QUEUE-1]){
            return queueArray;
        }else {
            ptr++;
            return ptr;
        }
    }

    void put(int data){
        if(full){
            cout<<"Error - Queue is full"<<endl;
            return;
        }
        *last = data;
        last = nextPtr(last);
        if(isVoid()){
            full = true;
        }
    }

    int get(){
        if(isVoid() && !full){
            cout<<"Error - Queue is empty"<<endl;
            return 0;
        }
        int data = *first;
        first = nextPtr(first);
        full = false;
        return data;
    }

    bool isVoid(){
        if (!full){
            return first == last;
        }else return false;
    }
};

int main()
{
    Queue q;
    for (int i =0; i < 11; i++){
        q.put(i);
    }
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
}
