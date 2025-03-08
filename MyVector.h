//
// Created by Bartłomiej Kruszyński on 23/05/2024.
//

#ifndef PROJECT_3_MYVECTOR_H
#define PROJECT_3_MYVECTOR_H


#include <cstdio>

class MyVector {
private:
    int* values;
    size_t size;
public:
    MyVector(size_t newSize, int initialValue = 0);
    MyVector(const MyVector& other);
    MyVector(MyVector&& other);
    MyVector& operator=(const MyVector& other);
    int& operator[](size_t index);
    size_t getSize() const;
    void print() const;
    ~MyVector();
};


#endif //PROJECT_3_MYVECTOR_H
