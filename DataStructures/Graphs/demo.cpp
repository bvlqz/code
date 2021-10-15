#include "Graph.h"
#include <iostream>

int main()
{
    std::cout << "Graph Example" << std::endl;
    
    Graph* G = new Graph();
    
    G->addNode("A", 0);
    G->addNode("B", 0);
    
    G->printAdjacencyMatrix();
    
    
    delete G;
}
