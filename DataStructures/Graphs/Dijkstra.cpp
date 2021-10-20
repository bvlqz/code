#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph* g)
{
    std::vector<Node*> nodes;
    g->getNodes(nodes);
    
    for (auto & node : nodes)
    {
        NodeInfo* ni = new NodeInfo();
        std::pair<std::string, NodeInfo*> i (node->getName(), ni);
        info.insert(i);
    }
}


void Dijkstra::setStartingNode(Node* n)
{
    info.find(n->getName())->second->shortestDistanceFromNode = 0;
    startingNode = n;
}

void Dijkstra::solve()
{
    
    // Examine unvisited neighbors on starting node
    std::vector<Edge*> neighbors;
    startingNode->getNeighbors(neighbors);
    
    for (auto const& neighbor : neighbors)
    {
        auto neighborInfo = info.find(neighbor->getEndNode()->getName())->second;
        
        NodeInfo* startingNodeInfo = info.find(startingNode->getName())->second;
        
        if (neighborInfo->visited) continue;
        
        // shortest distance from selected node + weight
        int distanceToNode = neighbor->getWeight() + startingNodeInfo->shortestDistanceFromNode;

        if (distanceToNode < neighborInfo->shortestDistanceFromNode)
        {
            neighborInfo->shortestDistanceFromNode = distanceToNode;
            neighborInfo->prevVertex = neighbor->getStartNode();
        }
    }
    
    printTable();
    
    solved = true;
}

void Dijkstra::printTable()
{
    
    
    std::cout << std::endl << "\t\t\tShortest" << std::endl;
    std::cout << "\t\t\tDistance\tPrevious" << std::endl;
    std::cout << "Vertex\t\tfrom " << startingNode->getName() << "\t\tNode" << std::endl << std::endl;
    for (auto const& node : info)
    {
        bool inf = node.second->shortestDistanceFromNode == std::numeric_limits<int>::max();
        bool null = node.second->prevVertex == nullptr;
        
        std::cout << node.first << "\t\t\t";
        
        if (inf) { std::cout << "INF"; }
        else { std::cout << node.second->shortestDistanceFromNode; }
        
        std::cout << "\t\t\t";
        
        if (null) { std::cout << "NULL"; }
        else { std::cout << node.second->prevVertex->getName(); }
        
        std::cout << "\t" << std::endl;
    }
    std::cout << std::endl;
}
