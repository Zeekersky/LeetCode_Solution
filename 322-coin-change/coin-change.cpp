class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        // int ans = helper(coins.size()-1, coins, amount, dp);
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);
        for(int j=0; j<=amount; j++){
            if(j%coins[0] == 0)
                prev[j] = j/coins[0];
            else prev[j] = 1e9;
        }
        for(int i=1; i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                int pick = INT_MAX;
                if(j >= coins[i]) pick = 1+curr[j-coins[i]];
                int notPick = prev[j];
                curr[j] = min(pick, notPick);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
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