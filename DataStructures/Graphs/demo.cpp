#include "Graph.h"
#include <iostream>

int main()
{
    std::cout << "Graph Example" << std::endl;
    
    Graph* G = new Graph();
    
    G->addNode("A", 1243);
    G->addNode("B", 563);
    G->addNode("C", 8764);
    G->addNode("D", 9753);
    G->addNode("E", 9753);

    G->addEgde("A", "B", 4);
    G->addEgde("A", "C", 1);
    
    G->addEgde("B", "C", 6);
    
    G->addEgde("C", "A", 4);
    G->addEgde("C", "B", 1);
    G->addEgde("C", "D", 2);
    
    std::cout << std::endl << "printAdjacencyList()" << std::endl;
    G->printAdjacencyList();
    
    std::cout << std::endl << "dephtFirstSearch()" << std::endl;
    G->dephtFirstSearch("A");
    
    std::cout << std::endl << "breadthFirstSearch()" << std::endl;
    G->breadthFirstSearch("A");
    
    
    delete G;
}
