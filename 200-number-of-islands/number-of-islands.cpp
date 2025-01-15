class Solution {
public:
    int numIslands(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size(), level = 1;
        queue<pair<int, int>> q;
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='1' && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        for(int k=q.size(); k>0; k--){
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();
                            if (x > 0 && mat[x-1][y] == '1' && !vis[x-1][y]) {
                                q.push({x-1, y});
                                vis[x-1][y] = 1;
                            }
                            if (y > 0 && mat[x][y-1] == '1' && !vis[x][y-1]) {
                                q.push({x, y-1});
                                vis[x][y-1] = 1;
                            }
                            if (x < n-1 && mat[x+1][y] == '1' && !vis[x+1][y]) {
                                q.push({x+1, y});
                                vis[x+1][y] = 1;
                            }
                            if (y < m-1 && mat[x][y+1] == '1' && !vis[x][y+1]) {
                                q.push({x, y+1});
                                vis[x][y+1] = 1;
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};