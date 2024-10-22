class Solution {
public:

    int helper(int n, vector<int> &dp){
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];
        int one = helper(n - 1, dp);
        int two = 0;
        if(n - 2 >= 0) two = helper(n - 2, dp);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};