class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        // return helper(0, -1, nums, dp);
        // return tabulation(nums);
        // return space_opt(nums);
        return more_opt(nums);
    }
    int more_opt(vector<int>& nums){
        vector<int> dp(nums.size(), 1);
        int maxi=1;
        for(int ind=0; ind<nums.size(); ind++){
            for(int prev=0; prev<ind; prev++){
                if(nums[prev]<nums[ind])
                    dp[ind] = max(1+dp[prev], dp[ind]);
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
    int space_opt(vector<int>& nums){
        int n=nums.size();
        vector<int> curr(n+1, 0), ahead(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int take = INT_MIN;
                if(j==-1 || nums[j]<nums[i]) take = 1+ahead[i+1];
                int notTake = ahead[j+1];
                curr[j+1] = max(take, notTake);
            }
            ahead = curr;
        }
        return ahead[0];
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