class Solution {
public:
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        // return helper(s.size(), p.size(), s, p, dp);
        // return tabulation(s, p);
        return space_optimization(s, p);
    }
    bool space_optimization(string& s, string& t){
        vector<bool> prev(t.size()+1, false), curr(t.size()+1, false);
        int j=1;
        while(j<=t.size() && t[j-1]=='*'){
            prev[j++] = true;
        }
        prev[0] = true;
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=t.size(); j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    if(t[j-1]=='?') curr[j] = prev[j-1];
                    else if(t[j-1]=='*') curr[j] = prev[j] || prev[j-1] || curr[j-1];
                    else curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[t.size()];
    }
    bool tabulation(string& s, string& t){
        vector<vector<bool>> dp(s.size()+1, vector<bool>(t.size()+1, false));
        int j=1;
        while(j<=t.size() && t[j-1]=='*'){
            dp[0][j++] = true;
        }
        dp[0][0] = true;
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=t.size(); j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if(t[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                    else if(t[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[s.size()][t.size()];
    }
    bool helper(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        // Base Case
        if(i==0 && j==0) return true;
        if(i==0) {
            if(t[j-1]=='*') return helper(i, j-1, s, t, dp);
            return false;
        }
        if(j==0) {
            return false;
        }
        
        if(dp[i][j]!= -1) return dp[i][j];
        if(s[i-1] == t[j-1]){
            dp[i][j] = helper(i-1, j-1, s, t, dp);
        }
        else{
            if(t[j-1]=='?') dp[i][j] = helper(i-1, j-1, s, t, dp);
            else if(t[j-1]=='*') dp[i][j] = helper(i-1, j, s, t, dp)||helper(i-1, j-1, s, t, dp)||helper(i, j-1, s, t, dp);
            else dp[i][j] = false;
        }
        return dp[i][j];
    }
};