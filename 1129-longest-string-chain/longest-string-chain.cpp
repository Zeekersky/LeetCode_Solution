class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        int maxi=1;
        for(int i=1; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(comp(words[i], words[prev]) && dp[i]<1+dp[prev])
                    dp[i] = 1+dp[prev];
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
    bool comp(string &s1, string& s2){
        if(s1.size() != s2.size()+1) return false;
        int j=0;
        int cnt = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (j < s2.size() && s1[i] == s2[j]) j++;
            else {
                cnt++;
                if (cnt > 1) return false;
            }
        }
        return true;
    }
};