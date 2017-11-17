/**
 *   Created by Den Kopach 17.11.2017
*/

#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include "../ArrayList.h"
#include "Animals.h"

using namespace std;

class Zoo{
private:

public:
    Zoo(){
    }

    void printAnimals(){
        int currentSizeArray = arrayPointers->size();
        for (int i = 0; i < currentSizeArray; i++){
            printAnimal(i);
        }
    }

    void printAnimal(int index){
        void* ptr = arrayPointers->getPointer(index);
        Animals* animal = static_cast<Animals *>(ptr);
        animal->printAnimal();
        cout<<endl;
    }

    void addAnimal(string name, int age, int paws, string kind){
        arrayPointers->add(new Animals (name, age, paws, kind));
    }

    void addAnimal(){
        string name, kind;
        int age, paws;
        cout<<"Enter name new animal"<<endl;
        cin>>name;
        cout<<"Enter age animal"<<endl;
        cin>>age;
        cout<<"How many paws?"<<endl;
        cin>>paws;
        cout<<"What kind animal?"<<endl;
        cin>>kind;
        arrayPointers->add(new Animals (name, age, paws, kind));
    }

    int findAnimal (){
        cout<<"Enter name animal"<<endl;
        string m_name;
        cin>>m_name;
        int sizeArrayPointer = arrayPointers->size();
        for (int i = 0; i < sizeArrayPointer; i++){
            Animals* animal = static_cast<Animals *>(arrayPointers->getPointer(i));
            string name = animal->getNameAnimal();
            if (name == m_name){
                return i;
            }
        }
        cout<<endl<<"There is no such animal!"<<endl<<endl;
        return -1;
    }

	void delAnimal (int index){
        arrayPointers->remove(index);
	}

	void editAnimal(int index){
        string kind;
        int age, paws;
        cout<<"Enter age animal"<<endl;
        cin>>age;
        cout<<"How many paws?"<<endl;
        cin>>paws;
        cout<<"What kind animal?"<<endl;
        cin>>kind;
        Animals* animal = static_cast<Animals *>(arrayPointers->getPointer(index));
        animal->setAnimal(age, paws, kind);
    }

    void exit(){

    }
};

#endif //ZOO_H
