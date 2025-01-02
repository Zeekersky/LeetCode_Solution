class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        string text2 = "";
        for(int i=s.size()-1; i>=0; i--)
            text2+=s[i];
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        // if(text1[0]==text2[0]) dp[0][0] = 1;
        // for(int i=1; i<text1.size(); i++){
        //     dp[i][0] = max((text1[i] == text2[0] ? 1 : 0), dp[i-1][0]);
        // }
        // for(int j=1; j<text2.size(); j++){
        //     dp[0][j] = max((text1[0] == text2[j] ? 1 : 0), dp[0][j-1]);
        // }
        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};