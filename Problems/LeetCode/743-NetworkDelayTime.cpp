// 743. Network Delay Time
// Becerra, Jorge Alberto

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printAdjacencyList(std::vector<std::vector<std::pair<int, int> > > adj)
{
    
  int idx = 0;
  std::cout << std::endl << "Adjacency List" << std::endl;
  for (auto& node : adj)
  {
    std::cout << idx << "(" << idx + 1 << ") -> ";
    for (auto& neighbor : node)
    {
      std::cout << "(" << neighbor.first << ", " << neighbor.second << ")";
    }
    std::cout << std::endl;
    idx++;
  }
  std::cout << std::endl;
}

void printPQ(std::priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > pq)
{
    while(!pq.empty()) {
        std::cout << "(" << pq.top().first << ',' << pq.top().second << ")";
        pq.pop();
    }
    std::cout << '\n';
}

class Solution {
private:
    std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int> > > graph, int nodes, int start)
    {
        // Vector of Minimun Known Distances
        std::vector<int> dist(nodes, std::numeric_limits<int>::max());
        dist[start] = 0;

        // Vector to check for already visited nodes
        std::vector <bool> visited(nodes, false);

        // Priority Queue: First element of pair is the distance (since is the one the priority
        // queue will be comparing), second element is the node index
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > pq;
        
        // The distance from the starting node to the starting node is 0
        pq.push(pair<int, int>( {0, start} ));
        
        // While the priority queue has elements
        while(!pq.empty())
        {
            printPQ(pq);
           
            // Get the best current distance of the node and the node index
            const int bestDist = pq.top().first;
            const int node = pq.top().second;
            
            // Mark node as visited, we wont be visiting node again
            visited[node] = true;
            pq.pop();

            // Iterate over the negihbors of the node
            for(auto& edge : graph[node])
            {
                // If we have already visited a neighbor, skip it
                if (visited[edge.first]) continue;
                
                // Get the accumulated distance
                int newDist = dist[node] + edge.second;
                
                // If we found a new distance lower tham the minimun known
                // distance for this node, update it and push it to the queue
                // to view its neighbors too
                if (newDist < dist[edge.first])
                {
                    dist[edge.first] = newDist;
                    pq.push(pair<int, int>( {newDist, edge.first} ));
                }
            }
        }

        // In this case, we don't care about the previous vertices
        // only the distances, so we return the array
        return dist;
        
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        // Initialize vectors to convert the times vector into an
        // adyacency list that we can work on
        std::vector<std::pair<int, int> > e; // Empty vector
        std::vector<std::vector<std::pair<int, int> > > adj(n, e);

        for (auto& time : times)
        {
            // Nodes start at 1, so we remove 1 from the vector id to we
            // can use it as an index
            adj[time[0] - 1].push_back(std::make_pair(time[1] - 1, time[2]));
        }

        printAdjacencyList(adj);
        
        // Remove 1 from k to convert it from a node id to an index
        auto dist = dijkstra(adj, n, k - 1);

        // Hold the maximum distance, since is the maximum time to
        // reach all nodes
        int maxDist = 0;
        
        for (auto& d : dist){
            // If any distance is "infinite", then there is at least a node that is unreachable
            if (d == std::numeric_limits<int>::max()) return -1;
            // If the current distance is greater that the max distance, update maxDist
            if (d > maxDist) maxDist = d;
        }
        return maxDist;
    }
};


int main()
{
    
    std::vector<std::vector<int> > times = {
        {2,4,10},
        {5,2,38},
        {3,4,33},
        {4,2,76},
        {3,2,64},
        {1,5,54},
        {1,4,98},
        {2,3,61},
        {2,1,0},
        {3,5,77},
        {5,1,34},
        {3,1,79},
        {5,3,2},
        {1,2,59},
        {4,3,46},
        {5,4,44},
        {2,5,89},
        {4,5,21},
        {1,3,86},
        {4,1,95}
    };

    int n = 5;
    int k = 1;
    
    Solution s;
    
    int result = s.networkDelayTime(times, n, k);
    
    std::cout
        << std::endl
        << "Time to reach all nodes: "
        << result
        << std::endl; // 3
}
