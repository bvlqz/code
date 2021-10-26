// 743. Network Delay Time
// Becerra, Jorge Alberto

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int> > > graph, int nodes, int start)
    {
        // Minimun Known Distance 
        std::vector<int> dist(nodes, std::numeric_limits<int>::max());
        dist[start] = 0;

        // Node has been visited
        std::vector <bool> visited(nodes, false);

        // NODE, DISTANCE
        // first -> node
        // second -> distance
        std::priority_queue<pair<int, int>> pq;
        pq.push(pair<int, int>( {start, 0} ));


        while(!pq.empty())
        {
            const int node = pq.top().first;
            const int bestDist = pq.top().second;

            visited[node] = true; 
            pq.pop();

            for(auto& edge : graph[node])
            {
                int newDist = dist[node] + edge.second; 
                if (newDist < dist[edge.first])
                {
                    dist[edge.first] = newDist;
                    pq.push(pair<int, int>( {edge.first, newDist} ));
                }
            }
        }
    return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        std::vector<std::pair<int, int> > e; 
        std::vector<std::vector<std::pair<int, int> > > adj(n, e);

        for (auto& time : times)
        {
          adj[time[0] - 1].push_back(std::make_pair(time[1] - 1, time[2]));
        }

        auto dist = dijkstra(adj, n, k - 1);

        int maxDist = 0; 
        for (auto& d : dist){
          if (d == std::numeric_limits<int>::max()) return -1;
          if (d > maxDist) maxDist = d;
        }
        return maxDist;
    }
};


int main()
{
    // Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    // Output: 2
    
    std::vector<std::vector<int> > times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    
    int n = 4;
    int k = 2;
    
    Solution s;
    std::cout << s.networkDelayTime(times, n, k) << std::endl;
}
