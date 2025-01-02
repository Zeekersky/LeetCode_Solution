class Solution {
public:
    int numDistinct(string s, string t) {
        // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        // return helper(s.size(), t.size(), s, t, dp);
        // return tabulation(s, t);
        return space_optimized(s, t);
    }
    int space_optimized(string &s, string &t){
        int MOD = 1e9 + 7;
        vector<int> prev(t.size()+1, 0), curr(t.size()+1, 0);
        for(int i=1; i<=s.size(); i++){
            prev[0] = 1;
            for(int j=1; j<=t.size(); j++){
                if(s[i-1]==t[j-1])
                    curr[j] = (prev[j-1]+prev[j])%MOD;
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[t.size()];
    }
    int tabulation(string &s, string &t){
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i=0; i<=s.size(); i++) dp[i][0] = 1;
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=t.size(); j++){
                if(s[i-1]==t[j-1])
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%MOD;
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int notTake = helper(i-1, j, s, t, dp);
        if(s[i-1]==t[j-1]){
            int take = helper(i-1, j-1, s, t, dp);
            return dp[i][j] = take+notTake;
        }
        return dp[i][j] = notTake;
    }
};