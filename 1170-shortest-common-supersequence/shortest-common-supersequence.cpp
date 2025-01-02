class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = LCS(str1, str2);
        int ind1 = 0, ind2 = 0;
        string ans = "";
        int i = 0;
        while (true) {
            bool flag1 = false;
            if (ind1 < str1.size()) {
                flag1 = true;
                while (str1[ind1] != lcs[i]) {
                    ans += str1[ind1++];
                }
            }
            bool flag2 = false;
            if (ind2 < str2.size()) {
                flag2 = true;
                while (str2[ind2] != lcs[i]) {
                    ans += str2[ind2++];
                }
            }
            if (i < lcs.size()){
                ans += lcs[i++];
                ind1++;
                ind2++;
            }
            if (!flag1 && !flag2) break;
        }
        return ans;
    }

    string LCS(string &text1, string &text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        int i = text1.size();
        int j = text2.size();
        int index = dp[i][j] - 1;
        string ans(dp[i][j], ' ');
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                ans[index--] = text1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return ans;
    }
};