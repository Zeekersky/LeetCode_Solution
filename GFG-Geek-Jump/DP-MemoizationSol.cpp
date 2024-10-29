class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here
        vector<int> dp(n + 1, -1);
        if (n <= 1)
            return 0;
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        return helper(n - 1, height, dp);
    }
    int helper(int ind, vector<int> &height, vector<int> &dp)
    {

        if (ind <= 1 || dp[ind] != -1)
            return dp[ind];
        dp[ind] = min(helper(ind - 1, height, dp) + abs(height[ind - 1] - height[ind]),
                      helper(ind - 2, height, dp) + abs(height[ind - 2] - height[ind]));
        return dp[ind];
    }
};