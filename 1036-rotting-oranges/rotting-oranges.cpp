class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            for(int n = q.size(); n>0; n--){
                pair<int,int> node = q.front();
                q.pop();
                int i=node.first;
                int j=node.second;
                if(i>0 && !vis[i-1][j]) {
                    if(grid[i-1][j] == 1){
                        q.push({i-1, j});
                        grid[i-1][j] = 2;
                    }
                    vis[i-1][j] = 1;
                }
                if(j>0 && !vis[i][j-1]) {
                    if(grid[i][j-1] == 1){
                        q.push({i, j-1});
                        grid[i][j-1] = 2;
                    }
                    vis[i][j-1] = 1;
                }
                if(i<grid.size()-1 && !vis[i+1][j]) {
                    if(grid[i+1][j] == 1){
                        q.push({i+1, j});
                        grid[i+1][j] = 2;
                    }
                    vis[i+1][j] = 1;
                }
                if(j<grid[i].size()-1 && !vis[i][j+1]) {
                    if(grid[i][j+1] == 1){
                        q.push({i, j+1});
                        grid[i][j+1] = 2;
                    }
                    vis[i][j+1] = 1;
                }
            }
            time++;
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        if(time == 0) return 0;
        return time-1;
    }
};