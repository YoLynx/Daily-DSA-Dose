// Problem Link - https://www.geeksforgeeks.org/shortest-path-in-a-grid-with-obstacles-elimination/
// Time Complexity: O(N * M * K), where N is the number of rows,

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1-based indexing
        vector<pair<int, int>> adj[n+1];
        for(auto it : times) {
            adj[it[0]].push_back({it[2], it[1]});  // {u, v} -> {weight, node}
        }

        // pq -> {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> time(n+1, 1e9);
        time[k]=0;

        while(!pq.empty()) {
            auto it=pq.top();
            pq.pop();

            int t=it.first;
            int node=it.second;

            for(auto iti : adj[node]) {
                int ti=iti.first;
                int adjnode=iti.second;

                if(ti+t<time[adjnode]) {
                    time[adjnode]=ti+t;
                    pq.push({ti+t, adjnode});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++) {
            ans=max(ans, time[i]);
        }

        if(ans>=1e9) return -1;
        return ans;


    }
};