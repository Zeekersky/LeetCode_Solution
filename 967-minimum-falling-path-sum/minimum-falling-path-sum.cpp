class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<n; i++)
            dp[0][i] = matrix[0][i];
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                int up = INT_MAX, left_corner = INT_MAX, right_corner = INT_MAX;
                if(i>0) up = dp[i-1][j];
                if(j>0 && i>0) left_corner = dp[i-1][j-1];
                if(j<n-1 && i>0) right_corner = dp[i-1][j+1];
                dp[i][j]= min(min(up, left_corner), right_corner) + matrix[i][j];
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