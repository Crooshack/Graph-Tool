//
// Created by Bartek Kruszyński on 08.03.2024.
//

#ifndef PROJECT_1_MYSTACKNODE_H
#define PROJECT_1_MYSTACKNODE_H


class MyStackNode {
private:
    MyStackNode* next{};
    int value;
public:
    MyStackNode(int newValue, MyStackNode* next);
    MyStackNode* getNext();
    int getValue() const;
};


#endif //PROJECT_1_MYSTACKNODE_H
