class Solution {
public:
    int helper(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == nums.size()) {
            return 0;
        }
        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        int ntaken = helper(i + 1, prev, nums, dp);
        int taken = prev == -1 or nums[i] > nums[prev] ? 1 + helper(i + 1, i, nums, dp) : 0;
        return dp[i][prev + 1] = max(ntaken, taken);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            if(val <= temp.back()) {
                int idx = lower_bound(temp.begin(), temp.end(), val) - temp.begin();
                temp[idx] = val;
            } else {
                temp.push_back(val);
            }
        }
        return temp.size();
    }
};