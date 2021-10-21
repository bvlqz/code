#include "Graph.h"
#include "Dijkstra.h"
#include <iostream>

int main()
{
    std::cout << "Graph Example" << std::endl;
    
    Graph* G = new Graph();
    
    G->addNode("A", 0);
    G->addNode("B", 1);
    G->addNode("C", 2);
    G->addNode("D", 3);
    G->addNode("E", 4);
    G->addNode("F", 4);

    G->addEgde("A", "B", 6, true);
    G->addEgde("A", "D", 1, true);
    G->addEgde("B", "D", 2, true);
    G->addEgde("B", "E", 2, true);
    G->addEgde("B", "C", 5, true);
    G->addEgde("C", "E", 5, true);
    G->addEgde("D", "E", 1, true);

    Dijkstra* d = new Dijkstra(G);
    d->setStartingNode(G->getNode("A"));
    d->printTable();
    d->solve();
    
    delete G;
}
