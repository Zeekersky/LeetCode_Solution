class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        // Case 1: Rob from index 0 to nums.size() - 2
        vector<long long> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            long long pick = (i >= 2) ? dp[i - 2] + nums[i] : nums[i];
            long long notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        long long max1 = dp[nums.size() - 2];

        // Case 2: Rob from index 1 to nums.size() - 1
        for(int i = 0; i<nums.size(); i++) dp[i] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            long long pick = (i > 2) ? dp[i - 2] + nums[i] : nums[i];
            long long notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        long long max2 = dp[nums.size() - 1];

        return max(max1, max2);
    }
};