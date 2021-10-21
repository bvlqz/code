#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include <vector>
#include <limits>

#include "Graph.h"
#include "Node.h"

struct NodeInfo
{
    bool visited;
    int shortestDistanceFromNode;
    Node* prevVertex;
    NodeInfo()
    {
        shortestDistanceFromNode = std::numeric_limits<int>::max();
        prevVertex = nullptr;
        visited = false;
    }
};

class Dijkstra
{
public:
    Dijkstra(Graph* g);
    void setStartingNode(Node* n);
    
    void solve();
    void solve(Node* n);
    
    void shortestPath(Node* n);
    void printTable();
    
private:
    Node* startingNode;
    std::map<std::string, NodeInfo*> info;
};


#endif // DIJKSTRA_H
