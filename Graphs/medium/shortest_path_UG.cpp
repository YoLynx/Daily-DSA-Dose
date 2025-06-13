// Problem Link : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Normal bfs


class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        vector<int> dis(n, -1);
        dis[src]=0;
        
        while(!q.empty()) {
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            
            for(auto it : adj[node]) {
                if(dis[it]==-1 || dis[it]>wt+1) {
                    dis[it]=wt+1;
                    q.push({it, wt+1});
                }
            }
            
        }
        
        return dis;
    }
};