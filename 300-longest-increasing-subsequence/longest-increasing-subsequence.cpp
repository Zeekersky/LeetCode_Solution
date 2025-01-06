class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return helper(0, -1, nums, dp);
    }
    int helper(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1]; // As prev goes: -1 to nums.size()-1
        int take = INT_MIN;
        if(prev == -1 || nums[prev]<nums[ind]) take = 1+helper(ind+1, ind, nums, dp);
        int notTake = helper(ind+1, prev, nums, dp);
        return dp[ind][prev+1] = max(take, notTake);
    }
};