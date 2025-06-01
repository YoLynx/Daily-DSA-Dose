// Problem Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// We divide it into 3 segments: left, overlap, right.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        int n=intervals.size();
        //left
        while(i<n && intervals[i][1]<newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        // overlap
        while(i<n && intervals[i][0]<=newInterval[1]) {
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        
        //right
        while(i<n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

