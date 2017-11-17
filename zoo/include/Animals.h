/**
 *   Created by Den Kopach 17.11.2017
*/
#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>
#include "Interface.h"

ArrayList* arrayPointers = new ArrayList;

class Animals {
private:
	int age;
    int pawsNum = 0;
	int health = rand() % 100;
	string kind = "";
	string name = "";
	bool isShow = true;
public:
	Animals(string name = "", int age = 0, int pawsNum = 0, string kind = ""){
		this->name = name;
		this->age = age;
		this->pawsNum = pawsNum;
		this->kind = kind;
        this->health = rand() % 100;
        this->isShow = true;
	}

    //output of animal data
    void printAnimal(){
		cout << endl << "Animal: " << this->name << endl;
		cout << "age: " << this->age << endl;
		cout << "paws: " << this->pawsNum << endl;
		cout << "kind: " << this->kind <<endl;
        cout << "health: " << this->health <<endl;
        cout << "isShow: " << this->isShow << endl <<endl;
	}

    //obtaining the meaning of the animal's name
    string getNameAnimal(){
        return this->name;
    }

    //change of animal data
    void setAnimal(int m_age, int m_pawsNum, string m_kind){
        this->age = m_age;
        this->pawsNum = m_pawsNum;
		this->kind = m_kind;
    }

    //request data for adding a new animal
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

    //clearing memory before shutting down
    void exit(){
        delete arrayPointers;
    }

};
#endif //ANIMALS_H
