// Problem Link : https://www.geeksforgeeks.org/problems/rotation4723/1

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0; 
        int high=arr.size()-1;
        int ans=INT_MAX;
        int index=-1;
        
        while(low<=high) {
            int mid=(low+high)/2;
            
            if(arr[low]<=arr[high]) {      // already sorted.
                if(arr[low]<ans) {
                    ans=arr[low];
                    index=low;
                }
                break;
            }
            
            if(arr[low]<=arr[mid]) {      // left half sorted.
                if(arr[low]<ans) {
                    ans=arr[low];
                    index=low;
                }
                low=mid+1;                // eliminate left half
            }
            else {                        // right half sorted.
                if(arr[mid]<ans) {
                    ans=arr[mid];
                    index=mid;
                } 
                high=mid-1;               // eliminate right half.
            }
        }
        return index;
    }
};