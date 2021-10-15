#include <vector>
#include <string>
#include <iostream>

/*
A graph

Becerra, Jorge Alberto <jorge@koruke.com>
Code
2021-07-10
*/

struct Vertex {
    int weight;
};

struct Node {
    
};

class Graph {

public:
    Graph()
    {
        std::vector< std::vector<int> > two_D_vector(2, std::vector<int>(2));
        adjacencyMatrix = two_D_vector;
        
    }

    void addNode(std::string name, int data)
    {
        nodeNames.push_back(name);
        
        
        
        
        /*
         [ 0 0 ]
         [ 0 0 ]
         */
         
        
    }
    
    void dijkstra() {}

    void printAdjacencyMatrix()
    {
        for (auto & nodeName : nodeNames) {
            std::cout << "\t" << nodeName;
        }
        std::cout << std::endl;
        
        for (int i = 0; i < adjacencyMatrix.size(); i++)
        {
            
            std::cout << nodeNames[i] << "\t";

            for (int j = 0; j < adjacencyMatrix[i].size(); j++)
            {
                std::cout << adjacencyMatrix[i][j] << "\t";
            }
            
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::string> nodeNames;
    std::vector< std::vector<int> > adjacencyMatrix; // Maybe even a map?
};
