//
// Created by Bartłomiej Kruszyński on 23/05/2024.
//

#include "MyVector.h"
#include <iostream>
#include <cstring>

using namespace std;

MyVector::MyVector(size_t newSize, int initialValue) {
    size = newSize;
    values = new int[size];

    //setting initial values
    memset(values, initialValue, size * sizeof(int));
}

MyVector::MyVector(const MyVector& other){
    size = other.size;
    values = new int[size];
    memcpy(values, other.values, size * sizeof(int));
}

MyVector::MyVector(MyVector&& other){
    size = other.size;
    values = other.values;

    other.size = 0;
    other.values = nullptr;
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this == &other) return *this;

    delete[] values;

    size = other.size;
    values = new int[size];
    memcpy(values, other.values, size * sizeof(int));

    return *this;
}

int& MyVector::operator[](size_t index) {
    return values[index];
}

size_t MyVector::getSize() const {
    return size;
}

void MyVector::print() const {
    for(size_t i=0; i<size; i++){
        cout<<values[i]<< ' ';
    }
}

MyVector::~MyVector(){
    delete[] values;
}