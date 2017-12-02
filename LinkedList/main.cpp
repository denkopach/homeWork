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
        }
        else{
            lastNode->nextNode = tmpNode;
            tmpNode->nextNode = NULL;
            lastNode = tmpNode;
        }
    }

    void addNode(int data, int index, Node* currentNode = NULL){
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
            addNode(data);
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

        if (count == 0){
            currentNode = firstNode;
        }
        if (index == 0){
            firstNode = firstNode->nextNode;
            return;
        }
        else if (count == index - 1){
            previosNode = currentNode;
            cout<<"Step1"<<endl;
        }
        if (count == index){
            previosNode->nextNode = currentNode->nextNode;
            delete currentNode;
            cout<<"Step2"<<endl;
            return;
        }
        if (currentNode->nextNode == NULL){
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
    linkList->addNode(12);
    linkList->addNode(45);
    linkList->addNode(234);
    linkList->addNode(24);
    linkList->addNode(44);


    linkList->addNode(2, 0);
    linkList->addNode(111, 9);
    linkList->removeNode(1);
    linkList->removeNode(0);

    linkList->show();
    int data;
    cin>>data;
    return 0;
}
