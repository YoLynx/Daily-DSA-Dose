// Problem Link : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        
        vector<pair<int, int>> v;
        
        for(int i=0;i<n;i++) {
            v.push_back({end[i], start[i]});
        }
        
        sort(v.begin(), v.end());
        
        int cnt=1;
        int freetime=v[0].first;
        
        for(int i=0;i<n;i++) {
            if(v[i].second>freetime) {
                cnt++;
                freetime=v[i].first;
            }
        }
        return cnt;
        
    }
};