class Solution {
public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        // return helper(word1.size(), word2.size(), word1, word2, dp);
        // return tabulation(word1, word2);
        return space_optimized(word1, word2);
    }
    int space_optimized(string& s, string& t){
        vector<int> prev(t.size()+1, 0), curr(t.size()+1, 0);
        for(int j=0; j<=t.size(); j++) prev[j] = j;
        for(int i=1; i<=s.size(); i++){
            curr[0] = i;
            for(int j=1; j<=t.size(); j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1];
                else
                    curr[j] = 1+min(curr[j-1], min(prev[j], prev[j-1]));
            }
            prev = curr;
        }
        return prev[t.size()];
    }
    int tabulation(string& s, string& t){
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i=0; i<=s.size(); i++) dp[i][0] = i;
        for(int j=0; j<=t.size(); j++) dp[0][j] = j;
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=t.size(); j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        return dp[s.size()][t.size()];
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