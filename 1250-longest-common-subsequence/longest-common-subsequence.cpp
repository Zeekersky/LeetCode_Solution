class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        // return helper(text1.size()-1, text2.size()-1, text1, text2, dp);
        return tabulation(text1, text2);
    }
    int tabulation(string text1, string text2){
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        if(text1[0]==text2[0]) dp[0][0] = 1;
        for(int i=1; i<text1.size(); i++){
            dp[i][0] = max((text1[i] == text2[0] ? 1 : 0), dp[i-1][0]);
        }
        for(int j=1; j<text2.size(); j++){
            dp[0][j] = max((text1[0] == text2[j] ? 1 : 0), dp[0][j-1]);
        }
        for(int i=1; i<text1.size(); i++){
            for(int j=1; j<text2.size(); j++){
                if(text1[i]==text2[j])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
    int helper(int i, int j, string &text1, string &text2, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return dp[i][j] = (text1[i] == text2[j] ? 1 : 0);
        }
        if (i == 0) {
            return dp[i][j] = max((text1[i] == text2[j] ? 1 : 0), helper(i, j - 1, text1, text2, dp));
        }
        if (j == 0) {
            return dp[i][j] = max((text1[i] == text2[j] ? 1 : 0), helper(i - 1, j, text1, text2, dp));
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j])
            dp[i][j] = 1+helper(i-1, j-1, text1, text2, dp);
        else {
            int t1Pick = helper(i, j-1, text1, text2, dp);
            int t2Pick = helper(i-1, j, text1, text2, dp);
            dp[i][j] = max(t1Pick, t2Pick);
        }
        return dp[i][j];
    }
};