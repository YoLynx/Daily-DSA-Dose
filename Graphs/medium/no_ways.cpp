// Problem Link : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/



class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // 0-based node indexing
        int MOD=(int)(1e9+7);
        vector<pair<int, int>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});   
        }

        // pq -> {dist, node};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> dist(n, 1e9), ways(n, 0);
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()) {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            // if (dis > dist[node]) continue;

            for(auto it : adj[node]) {
                int adjnode=it.first;
                int ew=it.second;

                //first time visit.
                if(dis+ew < dist[adjnode]) {
                    dist[adjnode]=dis+ew;
                    ways[adjnode]=ways[node];
                    pq.push({dis+ew, adjnode});
                }
                // other times
                else if(dis+ew == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};