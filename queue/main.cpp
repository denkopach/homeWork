#include <iostream>

using namespace std;

class Queue{
private:
    const int SIZE_QUEUE = 10;
    int* queueArray = new int[SIZE_QUEUE];
    int* last;
    int* first;
    bool fullQueue;

public:
    Queue(){
        first = queueArray;
        last = queueArray;
        fullQueue = false;
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
        if(fullQueue){
            cout<<"Error - Queue is full"<<endl;
            return;
        }
        *last = data;
        last = nextPtr(last);
        if(lastEquilFirst()){
            fullQueue = true;
        }
    }

    int get(){
        if(queueIsEmpty()){
            cout<<"Error - Queue is empty"<<endl;
            return 0;
        }
        int data = *first;
        first = nextPtr(first);
        fullQueue = false;
        return data;
    }

    //check queue for fullness
    bool queueIsEmpty(){
        if (!fullQueue){
            return lastEquilFirst();
        }else return false;
    }
    //checking for the last element is equal to the first
    bool lastEquilFirst(){
        return first == last;
    }

    ~Queue(){
        delete queueArray;
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
