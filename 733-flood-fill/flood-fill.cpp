class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // BFS Concept
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), 0));
        q.push({sr, sc});
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            int i=node.first;
            int j=node.second;
            int oldVal = image[i][j];
            image[i][j] = color;
            if(i>0 && !vis[i-1][j]) {
                if(image[i-1][j] == oldVal){
                    q.push({i-1, j});
                }
                vis[i-1][j] = 1;
            }
            if(j>0 && !vis[i][j-1]) {
                if(image[i][j-1] == oldVal){
                    q.push({i, j-1});
                }
                vis[i][j-1] = 1;
            }
            if(i<image.size()-1 && !vis[i+1][j]) {
                if(image[i+1][j] == oldVal){
                    q.push({i+1, j});
                }
                vis[i+1][j] = 1;
            }
            if(j<image[i].size()-1 && !vis[i][j+1]) {
                if(image[i][j+1] == oldVal){
                    q.push({i, j+1});
                }
                vis[i][j+1] = 1;
            }
        }
        return image;
    }
};