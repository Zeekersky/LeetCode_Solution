class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return helper(coins.size()-1, coins, amount, dp);
    }
    int helper(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount == 0 || (amount % coins[0]) == 0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int pick = 0;
        if(amount>=coins[ind]) pick = helper(ind, coins, amount-coins[ind], dp);
        int notPick = helper(ind-1, coins, amount, dp);
        return dp[ind][amount] = pick+notPick;
    }
};