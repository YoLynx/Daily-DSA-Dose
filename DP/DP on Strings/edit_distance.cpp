#include <bits/stdc++.h>
//#define all(s) s.begin(), s.end()
using namespace std;
using ll=long long;
using ull=unsigned long long;

const int _N=1e5+5;

int solve(int i, int j, string& s , string& t, vector<vector<int>>& dp) {
    
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s[i]==t[j]) return dp[i][j]=0+solve(i-1, j-1, s, t, dp);
    else return dp[i][j]=1+min(solve(i-1, j, s, t, dp), min(solve(i, j-1, s, t, dp), solve(i-1, j-1, s, t, dp)));
}


int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s, t;
	cin>>s>>t;
	int n=s.size();
	int m=t.size();
	
	vector<vector<int>> dp(n, vector<int>(m, -1));
	
	
	cout<<solve(n-1, m-1, s, t, dp)<<endl;
	
	return 0;
}