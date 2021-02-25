#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Stack::Stack()
{
}
/*
Stack::~Stack()
{
}
*/

void Stack::push(Disc* inData)
{
    Node* currentNode = this->pTop;
    Node* newNode = new Node;
    newNode->data = inData;
    this->pTop = newNode;
    newNode->pNext=currentNode;
}
Disc* Stack::pop()
{
    if(empty()){
        Disc* temp = new Disc;
        return temp;
    }
    Node* currentNode = this->pTop;

    Node* nextNode = currentNode->pNext;
    this->pTop = nextNode;
    return currentNode->data;
}

Disc* Stack::top()
{
    if(empty()){
        return nullptr;
    }
    return this->pTop->data;
}

bool Stack::empty()
{
    if(pTop == nullptr){
        return true;
    }
    return false;
}

void Stack::display() {
    //cout<<endl;
    Node *p1;
    p1 = pTop;
    while (p1 != NULL) {
        cout << ((Disc *) (p1->data))->toString() << "\t";
        p1 = p1->pNext;
    }
}
