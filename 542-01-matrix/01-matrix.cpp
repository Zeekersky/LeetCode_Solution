class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size(), level = 1;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            for(int n=q.size(); n>0; n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i>0 && !vis[i-1][j]) {
                    q.push({i-1, j});
                    mat[i-1][j] = level;
                    vis[i-1][j] = 1;
                }
                if(j>0 && !vis[i][j-1]) {
                    q.push({i, j-1});
                    mat[i][j-1] = level;
                    vis[i][j-1] = 1;
                }
                if(i<mat.size()-1 && !vis[i+1][j]) {
                    q.push({i+1, j});
                    mat[i+1][j] = level;
                    vis[i+1][j] = 1;
                }
                if(j<mat[i].size()-1 && !vis[i][j+1]) {
                    q.push({i, j+1});
                    mat[i][j+1] = level;
                    vis[i][j+1] = 1;
                }
            }
            level++;
        }
        return mat;
    }
};