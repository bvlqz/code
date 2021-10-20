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
    int distanceFromStartVertex;
    
    Node* prevVertex;
    
    //distance from start vertex
    
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
    void shortestPath(Node* n);
    void printTable();
    
private:
    bool solved;
    
    Node* startingNode;
    std::map<std::string, NodeInfo*> info;
};


#endif // DIJKSTRA_H
