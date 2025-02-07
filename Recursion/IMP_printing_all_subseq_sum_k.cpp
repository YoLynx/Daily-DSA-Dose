#include<bits/stdc++.h>
using namespace std;

void f(int i, vector<int>&a, vector<int>&ans, int k) {
  if(i==a.size()) {
    int sum=0;
    for(int j=0;j<ans.size();j++) sum+=ans[j];
    if(sum==k) {
      for(int j=0;j<ans.size();j++) cout<<ans[j]<<" ";
      cout<<endl;
    }
    return;
  }

  ans.push_back(a[i]);
  f(i+1, a, ans, k);
  ans.pop_back();
  f(i+1, a, ans, k);
}

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int k;
  cin>>k;
  vector<int> ans;

  f(0, a, ans, k);

  return 0;

}


// This is the code for printing all the subsequences whose sum is equal to k --> Important(IMP) Question.
// Time Complexity -> O(2^n) -> nearly exponential.  As we get 2^n subsequences.  Or 2^n recursive calls. and 2^n*n is the time complexity as we are printing the subsequence.