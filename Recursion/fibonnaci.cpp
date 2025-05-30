#include<bits/stdc++.h>
using namespace std;

int f(int n) {
  if(n<=1) return n;  // base case
  return f(n-1)+f(n-2);
}

int main() {
  int n;
  cin>>n;
  cout<<f(n);
  return 0; 
}

// Time Complexity: O(2^n) -> nearly which is exponential, because for each call, two function calls are made.

// Space Complexity: O(n) -> The space complexity of the recursive function is O(n) because the maximum depth of the recursion tree can go upto n.