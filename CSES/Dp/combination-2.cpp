#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int MOD=1e9+7;
 
ll f(int x, vector<int>& a, vector<ll>& dp, int ind) {
    if(x==0) return 1;
    if(x<0) return 0;
    if(dp[x]!=-1) return dp[x];
    
    ll res=0;
    
    res+=(f(x-a[ind], a, dp, ind))%MOD;
    res+=(f(x-a[ind], a, dp, ind+1))%MOD;

    return dp[x]=res%MOD;
    
}
 
int main() {
	int n, x;
	cin>>n>>x;
	vector<ll> dp(x+1, -1);
	vector<int> a(n); 
	for(int i=0;i<n;i++) cin>>a[i];
	
	cout<<f(x, a, dp, 0)<<endl;
 
}
