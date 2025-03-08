//
// Created by Bartek Kruszyński on 22.05.2024.
//

#include "Graph.h"
#include "MyStack.h"
#include "Constants.h"

Graph::Graph(int newOrderOfGraph){
    orderOfGraph = newOrderOfGraph;
    vertices = new MyVector*[orderOfGraph];
}

void Graph::createSpaceForNeighbors(int vertexIndex, size_t numberOfNeighbors){
    vertices[vertexIndex] = new MyVector(numberOfNeighbors);
}

Graph::~Graph(){
    for(int i=0; i<orderOfGraph; i++){
        delete vertices[i];
    }
    delete[] vertices;
}

MyVector** Graph::getVertices() const {
    return vertices;
}

long long int Graph::getNumberOfEdges() const{
    long long int numberOfEdges = 0;
    for(int i=0; i<orderOfGraph; i++) {
        MyVector& neighbors = *vertices[i];
        numberOfEdges += (long long int)neighbors.getSize();
    }
    return numberOfEdges/2;
}

// Na początku kod nie działał, ale po dodaniu ulepszenia dotyczącego dolnej granicy rozmiaru tablicy,
// zaproponowanego przez ChatGPT, wszystko zaczęło działać poprawnie – 
// przynajmniej tak mi się wydaje, bo nie pamiętam dokładnie.
MyVector Graph::degreeSequence() {
    //counting sort
    size_t minDegree = vertices[0]->getSize();
    size_t maxDegree = vertices[0]->getSize();
    for(int i=0; i<orderOfGraph; i++){
        if(vertices[i]->getSize() < minDegree){
            minDegree = vertices[i]->getSize();
        }
        if(vertices[i]->getSize() > maxDegree){
            maxDegree = vertices[i]->getSize();
        }
    }

    size_t range = maxDegree-minDegree+1;

    MyVector counter(range, 0);

    for(int i=0; i<orderOfGraph; i++){
        counter[vertices[i]->getSize()-minDegree]++;
    }

    MyVector degreeSequence(orderOfGraph, 0);

    for(int i=counter.getSize()-1, index=0; i>=0; i--){
        for(int j=0; j<counter[i]; j++){
            degreeSequence[index] = i+minDegree;
            index++;
        }
    }
    return degreeSequence;
}

int Graph::getNumberOfComponents(){
    MyVector wasVisited(orderOfGraph, Constants::NOT_VISITED);

    int numberOfComponents = 0;

    for(int i=0; i<orderOfGraph; i++){
        if(wasVisited[i] == Constants::VISITED){
            continue;
        }
        else{
            MyStack toTraverse;
            toTraverse.push(i);

            while(!toTraverse.isEmpty()){
                int vertexToCheck = toTraverse.pop();

                if(wasVisited[vertexToCheck]){
                    continue;
                }
                else{
                    wasVisited[vertexToCheck] = Constants::VISITED;
                }

                MyVector& neighbors = *vertices[vertexToCheck];
                for(size_t j=0; j<neighbors.getSize(); j++){
                    if(wasVisited[neighbors[j]-1] == Constants::NOT_VISITED){
                        toTraverse.push(neighbors[j]-1);
                    }
                }
            }
            numberOfComponents++;
        }
    }
    return numberOfComponents;
}

//wzorowane na pseudokodzie stad: https://eduinf.waw.pl/inf/alg/001_search/0131.php
bool Graph::bipartiteness(){
    MyVector colors(orderOfGraph, Constants::NO_COLOR);
    MyStack toTraverse;

    for(int i=0; i<orderOfGraph; i++) {
        if (colors[i] != Constants::NO_COLOR) {
            continue;
        }
        else {
            colors[i] = Constants::RED;

            toTraverse.push(i);
            while (!toTraverse.isEmpty()) {
                int vertexToCheck = toTraverse.pop();
                MyVector& neighbors = *vertices[vertexToCheck];
                for (size_t j = 0; j < neighbors.getSize(); j++) {
                    if (colors[neighbors[j] - 1] == colors[vertexToCheck]) {
                        return false;
                    } else if (colors[neighbors[j] - 1] != Constants::NO_COLOR) {
                        continue;
                    } else {
                        int neighborColor;
                        if (colors[vertexToCheck] == Constants::RED) {
                            neighborColor = Constants::BLUE;
                        } else {
                            neighborColor = Constants::RED;
                        }
                        colors[neighbors[j] - 1] = neighborColor;
                        toTraverse.push(neighbors[j] - 1);
                    }
                }
            }
        }
    }
    return true;
}



int Graph::C4SearchingDFS(int initialVertex, int vertexToCheck, int depthLeft, int previousVertex){
    if(depthLeft != 0) {
        MyVector& neighbors = *vertices[vertexToCheck];
        int c4Subgraphs = 0;
        for(size_t i=0; i<neighbors.getSize(); i++){
            if (neighbors[i] - 1 != previousVertex) {
                c4Subgraphs += C4SearchingDFS(initialVertex, neighbors[i] - 1, depthLeft - 1, vertexToCheck);
            }
        }
        return c4Subgraphs;
    }
    else {
        if(vertexToCheck == initialVertex){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int Graph::getNumberOfDifferentC4SubGraphs(){
    int c4Subgraphs = 0;
    //MyStack stack;
    for(int i=0; i<orderOfGraph; i++) {
//        //toTraverse
//        stack.push(i);
//        //max depth
//        stack.push(Constants::C4_DFS_DEPTH);
//        //previous vertex - first vertex
//        stack.push(i);
//        while(!stack.isEmpty()){
//            int previousVertex = stack.pop();
//            int currentVertexDepth = stack.pop();
//            int vertexToCheck = stack.pop();
//
//            if(currentVertexDepth != 0) {
//                MyVector& neighbors = *vertices[vertexToCheck];
//                for(size_t j=0; j<neighbors.getSize(); j++){
//                    if (neighbors[j] - 1 != previousVertex){
//                        //neighbors to traverse
//                        stack.push(neighbors[j] - 1);
//                        // depthLeft for neighbors
//                        stack.push(currentVertexDepth-1);
//                        //previous vertex for neighbors
//                        stack.push(vertexToCheck);
//                    }
//                }
//            }
//            else{
//                if(vertexToCheck == i){
//                    c4Subgraphs++;
//                }
//            }
//        }

        c4Subgraphs += C4SearchingDFS(i, i, Constants::C4_DFS_DEPTH, i);
    }
    return c4Subgraphs / 8;
}

long long int Graph::getNumberOfGraphComplementsEdges() const{
    long long int orderOfGraphInLongLongInt = (long long int)orderOfGraph;
    long long int numberOfCompleteGraphsEdges = orderOfGraphInLongLongInt*(orderOfGraphInLongLongInt-1)/2;
    return numberOfCompleteGraphsEdges - getNumberOfEdges();
}
