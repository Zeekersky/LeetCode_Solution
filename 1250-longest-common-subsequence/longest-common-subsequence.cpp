class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1.size()-1, text2.size()-1, text1, text2, dp);
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