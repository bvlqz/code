#include <vector>
#include <string>
#include <iostream>
#include <map>



/*
A graph

(a)-(b)
 |
(c)
 
(x) -> Vertex / Node
 -  -> Edge

Becerra, Jorge Alberto <jorge@koruke.com>
Code
2021-07-10
*/

struct Edge {
    bool exists;
    int weight;
    // direction?
};

struct Node {
    int data;
};

class Graph {

public:
    Graph();

    void checkConnectivity(); // Union find data structure,BFS, DFS
    void checkNegativeCicles(); // Bellman-Ford, Floyd-Warshall
    void checkStronglyConnectedComponents(); // Tarjan's, Kosaraju's
    void travelingSalesman(); // Held-Karp, branch and bound, etc.
    void minimunSpanningTree(); // (MST) Kruskal's, Prim's, Borůvka's
    void maxFlow(); // (Flow networks) Ford-Fulkerson, Edmonds-Karp, Dinic's algoritm
    void shortestPath(); // BFS (unweughted path), Dijkstra's, Bellman-Ford, Floyd-Warshall, A*, etc.
    
    
    void dephtFirstSearch(std::string at); // DFS

    void addNode(std::string name, int data);

    void printAdjacencyMatrix();
    void printAdjacencyList();
    
    void addEgde(std::string a, std::string b, int weight);

private:
    std::vector<std::string> nodeNames;
    int nodeCount;
    
    static std::vector<bool> tempDFSVisited;
    
    // Good for dense graphs (space efficient)
    // Not so good for sparse graphs
    std::vector< std::vector< int > > adjacencyMatrix;
    
    
    // Great for sparse graps
    // Efficient when iterating all the edges
    // std::map<std::string, int> adjacencyList;
    
    std::map< std::string, std::vector< std::pair< std::string, int > > > adjacencyList;
    
    
    
    std::map< std::string, bool > visitedMap;
};

