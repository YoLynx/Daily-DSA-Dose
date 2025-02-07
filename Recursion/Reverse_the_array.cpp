#include<bits/stdc++.h>
using namespace std;

void f(int i, vector<int>& a, int n) {
  if(i>=n/2) return;         // Base case
  
  swap(a[i], a[n-i-1]);

  f(i+1, a, n);

}

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  f(0, a, n);
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

// Time Complexity: O(n) -> nearly linear.