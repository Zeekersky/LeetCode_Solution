class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n=s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (dp[j] && linearSearch(wordDict,s.substr(j, i - j))) 
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
    
    bool linearSearch(vector<string>& vec, string target) 
    {
        for (int i = 0; i < vec.size(); i++) 
        {
            if (vec[i] == target)
                return true;
        }
        return false;
    }
};