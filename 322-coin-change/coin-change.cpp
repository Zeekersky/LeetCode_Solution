class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = helper(coins.size()-1, coins, amount, dp);
        if(ans == 0 || ans >= INT_MAX-1) return -1;
        else return ans;
    }
    int helper(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            return INT_MAX-1;
        }
        if (dp[ind][amount] != -1) return dp[ind][amount];
        int pick = INT_MAX;
        if(amount >= coins[ind]) pick = 1+helper(ind, coins, amount-coins[ind], dp);
        int notPick = helper(ind-1, coins, amount, dp);
        return dp[ind][amount] = min(pick, notPick);
    }
};