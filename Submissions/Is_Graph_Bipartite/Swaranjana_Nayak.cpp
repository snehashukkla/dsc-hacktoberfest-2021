// Is Graph Bipartite?
// Approach:
//    1. We are given adjacency list of graph
//    2. Breadth First Search is used to traverse the graph represented as adjacency list
//    3. Two vectors are created - one for partition marking, other for visted during BFS
//    4. For every node belonging to set A or B, the nodes in its adjacency list should belong to set B or A respectively
//    5. If the above condition is not satisfied for any node, graph is not bipartite
//    6. Else graph is bipartite
// Time Complexity: O(V+E) - adjacency list is used
// Space Complexity: O(V)

// Imports
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Solution class
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> nodes(n, 0);
        vector<bool> visited(n, false);

        int l = 0;
        int ind = 0;

        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() > l)
            {
                l = graph[i].size();
                ind = i;
            }
        }

        queue<int> q;
        q.push(ind);
        nodes[ind] = -1;
        visited[ind] = true;

        while (!q.empty())
        {

            int f = q.front();
            q.pop();

            for (int i : graph[f])
            {

                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }

                if (nodes[i] == 0)
                {
                    if (nodes[f] == -1)
                    {
                        nodes[i] = n;
                    }
                    else if (nodes[f] == n)
                    {
                        nodes[i] = -1;
                    }
                }
                else if (nodes[i] != nodes[f])
                {
                    continue;
                }
                else if (nodes[i] == nodes[f])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

// Main method
int main() {

    // Input
    // [[1,2,3],[0,2],[0,1,3],[0,2]]
    // stdin
    // 4
    // 1 2 3
    // 0 2
    // 0 1 3
    // 0 2

    int n; // number of nodes in the graph
    vector<vector<int>> adj_list;

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
    
        vector<int> v;
        int node;
        istringstream iss(s);
        while(iss >> node){
    	    v.push_back(node);
        }

        adj_list.push_back(v);
    }

    Solution sol;

    bool bipartite = sol.isBipartite(adj_list);
    cout << (bipartite == 0 ? "false" : "true");

    return 0;
}