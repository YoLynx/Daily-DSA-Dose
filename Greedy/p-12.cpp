// Problem Link : https://leetcode.com/problems/non-overlapping-intervals/
// Similar to n-meetings-in-one-room problem, but here we need to remove the minimum number of intervals to make them non-overlapping.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int res=0;
        int lastendtime=intervals[0][1];

        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0]<lastendtime) {
                res++; // overlapping interval, remove it
            } else {
                lastendtime=intervals[i][1]; // update end time
            }
        }
        return res;
    }
};