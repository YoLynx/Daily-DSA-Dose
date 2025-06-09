// Problem Link : https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // {{r, c}, t}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({{i, j}, 0});
                    vis[i][j]=2;
                }
            }
        }

        int tm=0;
        int drow[]={0, -1, 0, +1};
        int dcol[]={-1, 0, +1, 0};
        while(!q.empty()) {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm, t);
            q.pop();

            for(int i=0;i<4;i++) {
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]!=2) {
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc]=2;
                    grid[nr][nc]=2;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;  
            }
        }
        return tm;
    }
};