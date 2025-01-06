class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        // return helper(0, -1, nums, dp);
        return tabulation(nums);
    }
    int tabulation(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int take = INT_MIN;
                if(j==-1 || nums[j]<nums[i]) take = 1+dp[i+1][i+1];
                int notTake = dp[i+1][j+1];
                dp[i][j+1] = max(take, notTake);
            }
        }
        return dp[0][0];
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