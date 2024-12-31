class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
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
};