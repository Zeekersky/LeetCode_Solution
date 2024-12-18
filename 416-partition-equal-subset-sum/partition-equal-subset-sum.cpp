class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int arrSum = 0;
        for(int i=0; i<nums.size(); i++){
            arrSum += nums[i];
        }
        if(arrSum%2 != 0) return false;
        arrSum /= 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(arrSum+1, false));
        for(int i=0; i<nums.size(); i++) dp[i][0] = true;
        if (nums[0] <= arrSum) dp[0][nums[0]] = true;
        for(int i=1; i<nums.size(); i++){
            for(int j=1; j<=arrSum; j++){
                bool take = false;
                if(j > nums[i]) take = dp[i-1][j-nums[i]];
                bool notTake = dp[i-1][j];
                dp[i][j] = take | notTake;
            }
        }
        return dp[nums.size()-1][arrSum];
    }
};