//
// Created by Bartek Kruszyński on 08.03.2024.
//

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "MyStackNode.h"
#include "constants.h"


//content of the provided char table is copied to a new local char table
MyStackNode::MyStackNode(int newValue, MyStackNode* next) {
    this->value = newValue;
    this->next = next;
}

MyStackNode* MyStackNode::getNext(){
    return next;
}

int MyStackNode::getValue() const {
    return value;
}