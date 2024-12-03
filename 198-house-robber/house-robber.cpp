class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums.size()-1, nums, dp);
    }
    int helper(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return dp[ind] = nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = helper(ind-2, nums, dp) + nums[ind];
        int notPick = helper(ind-1, nums, dp);
        return dp[ind] = max(pick, notPick);
    }
};