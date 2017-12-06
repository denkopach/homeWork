/**
 *   Created by Den Kopach 25.11.2017
*/

#include <iostream>

using namespace std;

struct Node{
    Node *nextNode = NULL;
    int data;
};

class LinkedList{
private:
    Node* firstNode;
    Node* lastNode;
    Node* previosNode;
    Node* currentNode;
    Node* tmpNode;

    int count = 0;

public:
    LinkedList(){
        firstNode = NULL;
        lastNode = NULL;
    }

    void addNode(int data){
        tmpNode = new Node;
        tmpNode->data = data;
        tmpNode->nextNode = NULL;

        if(firstNode == NULL){
            firstNode = tmpNode;
            lastNode = tmpNode;
            tmpNode = NULL;
        }else{
            lastNode->nextNode = tmpNode;
            tmpNode->nextNode = NULL;
            lastNode = tmpNode;
        }
    }

    void addNode(int data, int index, Node* currentNode = NULL){
        if (index < 0){
            cout<<"ERROR! index out of range"<<endl;
            return;
        }
        if(count == 0){
            tmpNode = new Node;
            tmpNode->data = data;
            currentNode = firstNode;
        }
        if(index == 0){
            tmpNode->nextNode = firstNode;
            firstNode = tmpNode;
            count = 0;
            return;
        }
        if (currentNode->nextNode == NULL){
            cout<<"ERORR! index out of range"<<endl;
            return;
        }
        else if(count == index-1){
            tmpNode->nextNode = currentNode->nextNode;
            currentNode->nextNode = tmpNode;
            count = 0;
            return;
        }

        count++;
        currentNode = currentNode->nextNode;
        addNode(data, index, currentNode);
    }

    void show(){
        show(firstNode);
    }

    void show(Node* tmpNode){
        cout<<tmpNode->data<<endl;
        tmpNode = tmpNode->nextNode;
        if (tmpNode == NULL){
            return;
        }
        show(tmpNode);
    }

    void removeNode(int index, int count = 0){
        if (index < 0){
            cout<<"ERROR! index out of range"<<endl;
            return;
        }
        if (count == 0){
            currentNode = firstNode;
        }
        if (index == 0){
            firstNode = firstNode->nextNode;
            return;
        }
        else if (count == index - 1){
            previosNode = currentNode;
        }
        if (count == index){
            previosNode->nextNode = currentNode->nextNode;
            delete currentNode;
            return;
        }
        if (currentNode->nextNode == NULL){
            cout<<"ERROR! index out of range"<<endl;
            return;
        }
        currentNode = currentNode->nextNode;
        count++;
        removeNode(index, count);
    }
};

int main()
{
    LinkedList* linkList = new LinkedList;

    linkList->addNode(1);
    linkList->addNode(2);
    linkList->addNode(3);
    linkList->addNode(4);
    linkList->addNode(5);

    linkList->addNode(0, 0);
    linkList->addNode(111, 5);
    linkList->addNode(222, 3);
    linkList->addNode(33, 2);
    linkList->addNode(323, 1);

    linkList->removeNode(-146464654564654654654654654);
    linkList->removeNode(146464654564654654654654654);

    linkList->removeNode(2);

    linkList->show();

    return 0;
}
