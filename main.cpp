#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    size_t numberOfGraphs;
    cin >> numberOfGraphs;

    for(size_t i=0; i<numberOfGraphs; i++){
        //reading graph
        int orderOfGraph;
        cin >> orderOfGraph;
        Graph graph(orderOfGraph);
        MyVector** vertices = graph.getVertices();

        for(int j=0; j<orderOfGraph; j++){
            int numberOfNeighbors;
            cin >> numberOfNeighbors;
            graph.createSpaceForNeighbors(j, numberOfNeighbors);
            MyVector& neighbors = *vertices[j];
            for(int k=0; k < numberOfNeighbors; k++){
                int neighbor;
                cin >> neighbor;
                neighbors[k] = neighbor;
            }
        }

        cout<<endl;

        //processing graph
        //1
        MyVector degreeSequence(graph.degreeSequence());
        degreeSequence.print();
        cout<< endl;
        //2
        cout<< graph.getNumberOfComponents() <<endl;
        //3
        cout<< (graph.bipartiteness() ? 'T' : 'F') <<endl;
        //4
        cout<< '?' <<endl;
        //5
        cout<< '?' <<endl;
        //6a
        cout<< '?' <<endl;
        //6b
        cout<< '?' <<endl;
        //6c
        cout<< '?' <<endl;
        //7
        cout<< '?' <<endl;
        //cout<< graph.getNumberOfDifferentC4SubGraphs() <<endl;
        //8
        cout<< graph.getNumberOfGraphComplementsEdges() <<endl;
    }

    return 0;
}
