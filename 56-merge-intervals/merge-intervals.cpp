class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return (a[0]<b[0]) || (a[0]==b[0]&&a[1]<b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comp);
        int first = intervals[0][0];
        int last = intervals[0][1];
        int i = 1;
        while(i<=intervals.size()){
            while(i < intervals.size() && last>=intervals[i][0]){
                last = max(last, intervals[i][1]);
                i++;
            }
            ans.push_back({first, last});
            if(i<intervals.size()){
                first = intervals[i][0];
                last = intervals[i][1];
            }
            i++;
        }
        return ans;
    }
};