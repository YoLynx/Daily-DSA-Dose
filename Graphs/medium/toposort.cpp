// Problem Link : https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
  
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node]=1;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        
        vector<int> res;
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};





