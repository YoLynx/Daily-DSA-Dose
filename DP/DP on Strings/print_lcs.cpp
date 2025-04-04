// Prints only one lcs 
// Time complexity: O(n*m)

class Solution {
  public:
    vector<string> all_longest_common_subsequences(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=0;i<=n;i++) dp[i][0]=0;
       
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int len=dp[n][m];
        string s="";
        for(int i=0;i<len;i++) s+='|';
        
        int index=len-1;
        int i=n, j=m;
        while(i>0 && j>0) {
            if(text1[i-1]==text2[j-1]) {
                s[index]=text1[i-1];
                index--;
                i--, j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
        cout<<s;
    }
};