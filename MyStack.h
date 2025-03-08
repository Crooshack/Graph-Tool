//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_MYSTACK_H
#define PROJECT_1_MYSTACK_H


#include "MyStackNode.h"

class MyStack {
private:
    MyStackNode* top{};
public:
    MyStack();
    void push(int newValue);
    int pop();
    bool isEmpty() const;
    void printStack() const;
    ~MyStack();
};


#endif //PROJECT_1_MYSTACK_H
