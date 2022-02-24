class Solution {
public:
    static bool customSort(vector<int> a, vector<int> b){
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0])
            return a[1]>b[1];
        return false;
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customSort);
        int covered_intervals = 0, maximum_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= maximum_end) {
                covered_intervals++;
            }
            maximum_end = max(maximum_end, intervals[i][1]);
        }
        return intervals.size()-covered_intervals;
    }
};