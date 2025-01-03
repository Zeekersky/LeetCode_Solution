class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return helper(0, 1, prices, dp);
        return tabulation(prices);
    }
    int tabulation(vector<int>& prices){
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        for(int i=prices.size()-1; i>=0; i--){
            dp[i][0] = max(dp[i+1][0], prices[i]+dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1], dp[i+1][0]-prices[i]);
        }
        return dp[0][1];
    }
    int helper(int ind, bool buyFlag, vector<int>& prices, vector<vector<int>>& dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][buyFlag] != -1) return dp[ind][buyFlag];
        if(buyFlag){
            int notBuy = helper(ind+1, 1, prices, dp);
            int buy = helper(ind+1, 0, prices, dp) - prices[ind];
            return dp[ind][buyFlag] = max(buy, notBuy);
        }
        else{
            int notSell = helper(ind+1, 0, prices, dp);
            int sell = prices[ind] + helper(ind+1, 1, prices, dp);
            return dp[ind][buyFlag] = max(sell, notSell);
        }
    }
};