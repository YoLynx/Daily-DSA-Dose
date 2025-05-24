// Problem link : https://www.geeksforgeeks.org/first-negative-integer-in-every-window-of-size-k/
// Problem type: Sliding Window
// Queue is maintained to store the negative numbers in the current window.

class Solution {
  public:
    
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<int> d; 
        vector<int> res;
        int i=0, j=0;
    
        while(j<arr.size()) {
            if(arr[j]<0) d.push_back(arr[j]);
        
            if(j-i+1==k) {
                if(!d.empty()) res.push_back(d.front());
                else res.push_back(0);
                
                if(arr[i]<0 && !d.empty()) {
                    d.pop_front();
                }
                i++;
            }
            j++;
        }
        return res;
    }
};