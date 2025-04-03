#include <bits/stdc++.h>
//#define all(s) s.begin(), s.end()
using namespace std;
using ll=long long;
using ull=unsigned long long;

const int _N=1e5+5;
const int MOD=1e9+7;

ll solve(int n, int x, vector<int>& dp, vector<int>& a) {
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    
    if(dp[x]!=-1) return dp[x];
    
    int res=INT_MAX;
    for(int i=0;i<n;i++) {
        int minc=solve(n, x-a[i], dp, a);
        
        if(minc!=INT_MAX) {
            res=min(res, minc+1);
        }
    }
    
    
    return dp[x]=res;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, x;
	cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<int> dp(x+1, -1);
	int ans=solve(n, x, dp, a);
	 cout<<(ans==INT_MAX?-1 : ans)<<endl; 
	return 0;
}