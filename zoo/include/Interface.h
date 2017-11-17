/**
 *   Created by Den Kopach 17.11.2017
*/
#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include "../ArrayList.h"
#include "Animals.h"
#include "Zoo.h"

//allocate memory for classes
Zoo* zoo = new Zoo();
Animals* animal = new Animals;

class Interface{
private:

public:
    Interface(){

    }

    //main menu of the program
    void mainMenu(){
        int userChoise;
        do{
            cout<<"Select an action"<<endl;
            cout<<"1. Look all animals"<<endl;
            cout<<"2. Find animal in base and edit"<<endl;
            cout<<"3. Add animal"<<endl;
            cout<<"4. Exit"<<endl;
            cout<<endl;
            userChoise = this->getUserChoise();
        }while(userChoise <= 0 || userChoise > 5);

        switch (userChoise){
            case 1: {
                zoo->printAnimals();
                return;
            }
            break;
            case 2: {
                int index = zoo->findAnimal();
                if (index >= 0){
                    int answ = this->animalMenu(index);
                }
                return;
            }
            break;
            case 3: {
                zoo->addAnimal();
                return;
            }
            break;
            case 4: {
                this->progExit();
            }
            break;
            default: cerr << "error\n";
        }
        return;
    }

    //slave menu with animal data
    int animalMenu(int index){
        int userChoise;
        do{
            zoo->printAnimal(index);
            cout<<"Select an action"<<endl;
            cout<<"1. Edit animal"<<endl;
            cout<<"2. Delete animal"<<endl;
            cout<<"3. Find another animal"<<endl;
            cout<<"4. Go main menu"<<endl;
            cout<<endl;
            userChoise = this->getUserChoise();
        }while(userChoise <= 0 || userChoise > 4);

        switch (userChoise){
            case 1: {
                zoo->editAnimal(index);
                zoo->printAnimal(index);
                return (1);
            }
            break;
            case 2: {
                zoo->delAnimal(index);
                return(1);
            }
            break;
            case 3: {
                int index = zoo->findAnimal();
                this->animalMenu(index);
                return(1);
            }
            break;
            case 4: {
                return (1);
            }
            break;
            default: cerr << "error\n";
        }
        return (0);
    }

    //Process the user's choice
    int getUserChoise(){
        int input = 0;
        cin>>input;
        cin.clear();
        cin.ignore(10, '\n');
        return input;
    }

    //exit from the program with the release of memory in all classes
    void progExit(){
        delete zoo;
        delete animal;
        delete arrayPointers;
        animal->exit();
        zoo->exit();
        exit(1);
    }


};
#endif //INTERFACE_H
