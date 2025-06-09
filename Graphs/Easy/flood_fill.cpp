// Problem Link : https://leetcode.com/problems/flood-fill/

class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int dr[], int dc[], int color, int inicolor) {
        ans[row][col]=color;
        int n=ans.size();
        int m=ans[0].size();

        for(int i=0;i<4;i++) {
            int nr=row+dr[i];
            int nc=col+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==inicolor && ans[nr][nc]!=color)
            dfs(nr, nc, ans, image, dr, dc, color, inicolor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;

        int dr[]={-1, 0, +1, 0};
        int dc[]={0, +1, 0, -1};
        dfs(sr, sc, ans, image, dr, dc, color, inicolor);
        return ans;
    }
};