/**
 *   Created by Den Kopach 17.11.2017
 *   ArrayList class with an array of void*
*/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

using namespace std;

class ArrayList{
private:
    const int PRIMARY_SIZE = 10;

    int currentSize = 0;
    int maxSize = PRIMARY_SIZE;
    void** array;

    //the maximum size of the array is doubled
    void doublingSize(){
        void** tmpArray = new void*[maxSize*2];
        for(int i = 0; i < maxSize; i++){
            tmpArray[i] = array[i];
        }
        delete array;
        maxSize *= maxSize;
        array = new void*[maxSize];
        for(int i = 0; i < maxSize; i++){
            array[i] = tmpArray[i];
        }
        delete tmpArray;
    }

public:
    ArrayList(){
        array = new void*[maxSize];
        return;
    }

    ArrayList(int arraySize){
        array = new void*[arraySize];
        maxSize = arraySize;
        return;
    }

    //array output
    void print(){
        for(int i = 0; i < currentSize; i++){
            cout<<array[i]<< " " ;
        }
    }

    //adding an item to the end of the list
    void add(void* a){
        if (currentSize >= maxSize){
            this->doublingSize();
        }
        array[currentSize] = a;
        currentSize++;
    }

    //inserting an element by index
    void add (void* a, int index){
        index = index - 1;
        if (currentSize+1 >= maxSize){
            this->doublingSize();
        }
        void** tmpArray = new void*[maxSize-index];
        for(int i = index, j = 0; i < maxSize; i++, j++){
            tmpArray[j] = array[i];
        }
        array[index] = a;
        for (int i = index + 1, j = 0; i < maxSize; i++, j++){
            array[i] = tmpArray[j];
        }
        delete tmpArray;
        currentSize++;
    }

    //Deleting an array element for index
    void remove (int index){
        void** tmpArray = new void*[maxSize - index];
        for(int i = index, j = 0; i < maxSize; i++, j++){
            tmpArray[j] = array[i];
        }
        for (int i = index-1, j = 0; i < maxSize; i++, j++){
            array[i] = tmpArray[j];
        }
        delete tmpArray;
        currentSize--;
    }

    //check for the presence of a value
    int checkValue (void* a){
        for (int index = 0; index < currentSize; index++){
            if (array[index] == a){
                return index;
            }
        }
        return -1;
    }

    //Deleting an array element for value
    void remove (void* a){
        int index = this->checkValue(a);
            cout<<index<<endl;

        if (index > 0){
            this->remove(index);
        }
    }

    //Get poiner by index
    void* getPointer (int index){
        return array[index];
    }

    int size(){
        return currentSize;
    }
};

#endif // ARRAYLIST_H
