class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<m; i++){
            for(int j=0; j<=i; j++){
                int corner = INT_MAX, up = INT_MAX;
                if(j>0) corner = dp[i-1][j-1];
                if(j<i) up = dp[i-1][j];
                dp[i][j] = min(up, corner) + triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            ans = min(ans, dp[m-1][i]);
        }
        return ans;
    }
};