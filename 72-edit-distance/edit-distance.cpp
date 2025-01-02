class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return helper(word1.size(), word2.size(), word1, word2, dp);
    }
    int helper(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        int shrink = helper(i-1, j-1, s, t, dp);
        if(s[i-1]==t[j-1]) return dp[i][j] = shrink;
        else{
            int ins = 1+helper(i, j-1, s, t, dp);
            int del = 1+helper(i-1, j, s, t, dp);
            int repl = 1+shrink;
            return dp[i][j] = min(ins, min(del, repl));
        }
    }
};