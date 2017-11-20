/**
 *   Created by Den Kopach 17.11.2017
 *   ArrayList class with an array of int
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
    int* array;

    //the maximum size of the array is doubled
    void doublingSize(){
        int* tmpArray = new int[maxSize*2];
        for(int i = 0; i < maxSize; i++){
            tmpArray[i] = array[i];
        }
        delete array;
        maxSize *= maxSize;
        array = new int[maxSize];
        for(int i = 0; i < maxSize; i++){
            array[i] = tmpArray[i];
        }
        delete tmpArray;
    }

public:
    ArrayList(){
        array = new int[maxSize];
        return;
    }

    ArrayList(int arraySize){
        array = new int[arraySize];
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
    void add(int a){
        if (currentSize >= maxSize){
            this->doublingSize();
        }
        array[currentSize] = a;
        currentSize++;
    }

    //inserting an element by index
    void add (int a, int index){
        index = index - 1;
        if (currentSize+1 >= maxSize){
            this->doublingSize();
        }
        int* tmpArray = new int[maxSize-index];
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
        int* tmpArray = new int[maxSize - index];
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
    int checkValue (int a){
        for (int index = 0; index < currentSize; index++){
            if (array[index] == a){
                return index;
            }
        }
        return -1;
    }

    //Get value by index
    int getPointer (int index){
        return array[index];
    }

    int size(){
        return currentSize;
    }

    void trimToSize(){
        int* tmpArray = new int[currentSize];
        for(int i = 0; i < currentSize; i++){
            tmpArray[i] = array[i];
        }
        delete array;
        array = new int[currentSize];
        for(int i = 0; i < currentSize; i++){
            array[i] = tmpArray[i];
        }
        delete tmpArray;
    }
};

#endif // ARRAYLIST_H
