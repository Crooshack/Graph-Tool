//
// Created by Bartek Kruszyński on 08.03.2024.
//

#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include <iostream>
#include "MyStack.h"

MyStack::MyStack() {
    this->top = nullptr;
}

//push element on stack
//content of the provided char table is copied to a new local char table
void MyStack::push(int newValue) {
    MyStackNode* newElement = new MyStackNode(newValue, top == nullptr ? nullptr : top);
    top = newElement;
}

//the return value is copied to the provided char table
int MyStack::pop() {
    if(!this->isEmpty()){
        MyStackNode* temp = this->top;
        this->top = this->top->getNext();
        int value = temp->getValue();
        delete temp;
        return value;
    }
    //if stack is empty return empty string
    else{
        return -1;
    }
}

// print all stack elements separated with spaces
void MyStack::printStack() const {
    MyStackNode* temp = top;
    while (temp != nullptr) {
        std::cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

//check if empty
bool MyStack::isEmpty() const {
    if(top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

//if stack not empty, delete all elements left
MyStack::~MyStack(){
    if(!this->isEmpty()){
        MyStackNode* temp = top;
        MyStackNode* temp2 = top->getNext();
        while(temp != nullptr){
            delete temp;
            temp = temp2;
            if(temp != nullptr)
                temp2 = temp->getNext();
        }
    }
}




