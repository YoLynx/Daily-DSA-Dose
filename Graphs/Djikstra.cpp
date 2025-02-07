#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
vector<pair<int, int>> graph[MAXN];
long long dist[MAXN];
int parent[MAXN];

void dijkstra(int start, int n) {

    for(int i=1;i<=n;i++) {
        dist[i]=LLONG_MAX;
        parent[i]=0;
    }
    dist[start]=0;
    
    set<pair<long long, int>> s;
    s.insert({0, start});
    
    while (!s.empty()) {
        int u=s.begin()->second;
        long long d=s.begin()->first;
        s.erase(s.begin());
        
        for (auto& edge : graph[u]) {
            int v=edge.first;
            int w=edge.second;
            
            if(dist[u]+w<dist[v]) {
                if(dist[v]!=LLONG_MAX) {
                    s.erase({dist[v], v});
                }
            
                dist[v]=dist[u]+w;
                parent[v]=u;
                s.insert({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    
    for(int i=1;i<=m;i++) {
        int a, b, w;
        cin>>a>>b>>w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    
    dijkstra(1, n);
    
    if (dist[n]==LLONG_MAX) {
        cout<<-1<<endl;
        return 0;
    }
    
    vector<int> path;
    for (int v=n;v!=0; v=parent[v]) {
        path.push_back(v);
    }
    
    for(int i=path.size()-1;i>=0;i--) {
        cout<<path[i]<<" ";
    }
    cout << endl;
    
    return 0;
}