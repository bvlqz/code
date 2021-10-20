#include "Graph.h"

Graph::Graph()
{
    // Is the graph directed or undirected?
    // Are the edges of the graph weighted?
    // Is the graph likely to be sparse or dense with edges?
    // Should I use an  Adjancency Matrix, Adjancency List, an Edge List or other structure to represent the graph efficiently?
        
}

Graph::~Graph(){
    // Iterate over Node pointers and delete them
}


// Breadth First Search
// Mantains a queue on wich node it should visit next
void Graph::breadthFirstSearch(std::string at)
{

}



// Recursive Depht First Search
/*
void Graph::dephtFirstSearch(std::string at)
{
    
    // Skip if already visited
    if (!(visitedMap.find(at) == visitedMap.end())) return;
    
    visitedMap.insert( std::pair<std::string, bool>( at , true));
    
    std::cout << "Visited Node(s): ";
    for (auto const& visited : visitedMap)
    {
        std::cout << visited.first << " ";
    }
    std::cout << std::endl;
        
    for (auto const& neighbours : adjacencyList)
    {
        for (auto const& neighbour : neighbours.second)
        {
            dephtFirstSearch(neighbour.first);
        }
    }
}
 */

void Graph::addNode(std::string name, int data)
{
    // Skip if node alredy exists
    if (!(adjacencyList.find(name) == adjacencyList.end())) return;
    
    std::pair<std::string, int> l(name, 0);
    adjacencyList.insert(l);
    
    nodeCount++;
    nodeNames.push_back(name);
    
    
    // Using node pointers
    Node * n = new Node(name, data);
    nodes.push_back(n);
    
    std::pair<std::string, Node*> nn (name, n);
    nodeLocator.insert(nn);
}

void Graph::addEgde(std::string a, std::string b, int weight, bool undirected)
{
    auto aNode = nodeLocator.find(a);
    auto bNode = nodeLocator.find(b);
    if (aNode == nodeLocator.end() || bNode == nodeLocator.end())
    {
        std::cout << "Node not found";
        return;
    }
    aNode->second->addEdge(bNode->second, weight);
    if (undirected) bNode->second->addEdge(aNode->second, weight);
}
    

/*
void Graph::addNode(std::string name, int data)
{
    nodeNames.push_back(name);
    
    // Create a new vector with adjacencyMatrix.size, and fill it with weight 1
    std::vector<int> nodeRow(adjacencyMatrix.size(), 1);
    adjacencyMatrix.push_back(nodeRow);
    
    for (auto & row : adjacencyMatrix) {
        row.push_back(1);
    }
    
    adjacencyMatrix[adjacencyMatrix.size() - 1][adjacencyMatrix.size() - 1] = 0;
}
 */

void Graph::printAdjacencyMatrix()
{
    std::cout << std::endl << " ";
    for (auto & nodeName : nodeNames) {
        std::cout << " " << nodeName;
    }
    std::cout << std::endl;
    
    for (int i = 0; i < adjacencyMatrix.size(); i++)
    {
        
        std::cout << nodeNames[i] << " ";

        for (int j = 0; j < adjacencyMatrix[i].size(); j++)
        {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::printAdjacencyList()
{
    for (auto const& edgesList : adjacencyList)
    {
        std::cout << "(" << edgesList.second.size() << ")\t" ;
        std::cout << edgesList.first << " ->\t [" ;

        for (auto & edge : edgesList.second)
        {
            std::cout << "(" << edge.first << ", " << edge.second << "),";
        }
        
        std::cout << "]" << std::endl;
    }
}
