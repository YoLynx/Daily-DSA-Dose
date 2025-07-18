// Problem Link : https://leetcode.com/problems/path-with-minimum-effort/
// Dijsktra's Algorithm is used to find the minimum effort path in a grid.
// Time Complexity: O(N * M * log(N * M)), where N is the number of rows and M is the number of columns in the grid.
// Space Complexity: O(N * M), where N is the number of rows and M is the number of columns in the grid.

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0]=0;
        pq.push({0, {0, 0}});

        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};

        while(!pq.empty()) {
            auto it=pq.top();
            pq.pop();

            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;

            if(r==n-1 && c==m-1) return diff;

            for(int i=0;i<4;i++) {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int neff=max(abs(heights[r][c]-heights[nr][nc]), diff); // to handle the minimum we have taken a pq
                    if(neff<dist[nr][nc]) {
                        dist[nr][nc]=neff;
                        pq.push({neff, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};