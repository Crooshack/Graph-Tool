//
// Created by Bartek Kruszyński on 22.05.2024.
//

#ifndef PROJECT_3_GRAPH_H
#define PROJECT_3_GRAPH_H


#include "MyVector.h"

using namespace std;

class Graph {
private:
    int orderOfGraph;
    MyVector** vertices;
    int C4SearchingDFS(int initialVertex, int vertexToCheck, int depthLeft, int previousVertex);
public:
    explicit Graph(int newOrderOfGraph);
    void createSpaceForNeighbors(int vertexIndex, size_t numberOfNeighbors);
    MyVector** getVertices() const;
    long long int getNumberOfEdges() const;

    //1
    MyVector degreeSequence();
    //2
    int getNumberOfComponents();
    //3
    bool bipartiteness();
    //7
    int getNumberOfDifferentC4SubGraphs();
    //8
    long long int getNumberOfGraphComplementsEdges() const;
    ~Graph();
};


#endif //PROJECT_3_GRAPH_H
