//Problem Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto &it : edges) {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
        }
        
        vector<int> dis(V, 1e9);
        
        dis[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]) {
                int adjnode=it.first;
                int edgewt=it.second;
                
                if(dist+edgewt<dis[adjnode]) {
                    dis[adjnode]=dist+edgewt;
                    pq.push({edgewt+dist, adjnode});
                }
            }
        }
        return dis;
    }
};