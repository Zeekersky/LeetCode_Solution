class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                int up = 0, left = 0;
                if(i>0 && obstacleGrid[i-1][j] != 1)
                    up = dp[i-1][j];
                if(j>0 && obstacleGrid[i][j-1] != 1)
                    left = dp[i][j-1];
                if(obstacleGrid[i][j] != 1)
                    dp[i][j]=up+ left;
            }
        }
        return dp[m-1][n-1];
    }
};