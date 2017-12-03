/**
 *   Created by Den Kopach 21.11.2017
 *   ArrayList class with an array of void*
*/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

using namespace std;
template <class Type>
class ArrayList{
private:
    const int PRIMARY_SIZE = 10;

    int currentSize = 0;
    int maxSize = PRIMARY_SIZE;
    Type* array;

    //the maximum size of the array is doubled
    void doublingSize(){
        Type* tmpArray = new Type[maxSize*2];
        for(int i = 0; i < maxSize; i++){
            tmpArray[i] = array[i];
        }
        delete array;
        maxSize = maxSize*2;
        array = tmpArray;
    }

public:
    ArrayList(){
        array = new Type[maxSize];
        return;
    }

    ArrayList(int arraySize){
        array = new Type[arraySize];
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
    void add(Type a){
        if (currentSize >= maxSize){
            this->doublingSize();
        }
        array[currentSize] = a;
        currentSize++;
    }

    //inserting an element by index
    void add (Type a, int index){
        index = index - 1;
        if (currentSize+1 >= maxSize){
            this->doublingSize();
        }
        for(int i = currentSize+1; i > index; i-- ){
            array[i] = array[i-1];
        }
        array[index] = a;
        currentSize++;
    }

    //Deleting an array element for index
    void remove (int index){
        for(int i = index; i < currentSize - 1; i++){
            array[i] = array[i + 1];
        }
        currentSize--;
    }

    //check for the presence of a value
    int checkValue (Type a){
        for (int index = 0; index < currentSize; index++){
            if (array[index] == a){
                return index;
            }
        }
        return -1;
    }

    //Get poiner by index
    Type get(int index){
        return array[index];
    }

    int size(){
        return currentSize;
    }

    void trimToSize(){
        Type* tmpArray = new Type[currentSize];
        for(int i = 0; i < currentSize; i++){
            tmpArray[i] = array[i];
        }
        delete array;
        array = tmpArray;
    }
};

#endif // ARRAYLIST_H
