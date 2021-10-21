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
    info.find(this->startingNode->getName())->second->shortestDistanceFromNode = 0;
    solve(this->startingNode);
    
}

void Dijkstra::solve(Node* n)
{
    std::vector<Edge*> neighbors;
    n->getNeighbors(neighbors);
    
    NodeInfo* currentNode = info.find(n->getName())->second;
    
    int minDist = std::numeric_limits<int>::max();
    Node* nextNode = nullptr;
    
    for (auto const& neighbor : neighbors)
    {
        NodeInfo* neighborNode = info.find(neighbor->getEndNode()->getName())->second;
        if (neighborNode->visited) continue;
        
        
        int dist = currentNode->shortestDistanceFromNode + neighbor->getWeight();
        
        if (dist < neighborNode->shortestDistanceFromNode)
        {
            neighborNode->shortestDistanceFromNode = dist;
            neighborNode->prevVertex = n;
            
            if (dist < minDist) nextNode = neighbor->getEndNode();
        }

    }
    printTable();
    currentNode->visited = true;
    if (nextNode != nullptr) solve(nextNode);
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
