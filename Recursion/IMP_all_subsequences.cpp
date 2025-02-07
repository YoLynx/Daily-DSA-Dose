#include<bits/stdc++.h>
using namespace std;

void f(int i, vector<int>& a, int n, vector<int>& v) {
  if(i>=n) {
      for(int x : v) cout<<x<<" "; 
      cout<<endl;
      return;
    }
  v.push_back(a[i]);     // This is the case when we want to include the element in the subsequence.
  f(i+1, a, n, v);
  v.pop_back();       // This is the case when we don't want to include the element in the subsequence.
  f(i+1, a, n, v);
}

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  vector<int> v;
  f(0, a, n, v);
  return 0;
}


// This is an important Question from Recursion Section.
// Time Complexity: O(2^n) -> nearly exponential.  As we get 2^n subsequences.  Or 2^n recursive calls. and 2^n*n is the time complexity as we are printing the subsequence.