class Solution
{
public:
    int minimizeCost(int k, vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int min_step = INT_MAX;
            for (int j = ((i <= k) ? 0 : i - k); j < i; j++)
                min_step = min(min_step, dp[j] + abs(arr[i] - arr[j]));
            dp[i] = min_step;
        }
        return dp[n - 1];
    }
};