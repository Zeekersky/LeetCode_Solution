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
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return helper(0, -1, nums, dp);
    }
};