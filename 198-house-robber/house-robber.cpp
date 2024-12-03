class Solution {
public:
    int rob(vector<int>& nums) {
        // return mem(nums);
        return tab(nums);
    }
    int tab(vector<int> &nums){
        vector<int> dp(nums.size(), -1);
        if(nums.empty()) return 0;
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            int pick = INT_MIN;
            if(i>1) pick = dp[i-2] + nums[i];
            else pick = nums[i];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        for(auto it:dp) cout << it << " ";
        return dp[nums.size()-1];
    }
    int mem(vector<int>& nums) {
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