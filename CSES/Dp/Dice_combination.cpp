#include <bits/stdc++.h>
//#define all(s) s.begin(), s.end()
using namespace std;
using ll=long long;
using ull=unsigned long long;

const int _N=1e5+5;
const int MOD=1e9+7;

ll solve(int n, vector<ll>& dp) {
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    
    ll res=0;
    for(int i=1;i<7;i++) {
        if(n-i>=0) {
            res+=(solve(n-i, dp)%MOD);
        }
    }
    return dp[n]=res%MOD;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	vector<ll> dp(n+1, -1);
	cout<<solve(n, dp)<<endl;
	return 0;
}