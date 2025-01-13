class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size(), m=board[0].size(), count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 1) dfs(i, 0, board, vis);
            if(!vis[i][m-1] && board[i][m-1] == 1) dfs(i, m-1, board, vis);
        }
        for(int j=1; j<m-1; j++){
            if(!vis[0][j] && board[0][j] == 1) dfs(0, j, board, vis);
            if(!vis[n-1][j] && board[n-1][j] == 1) dfs(n-1, j, board, vis);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 1) count++; 
            }
        }
        return count;
    }
    void dfs(int i, int j, vector<vector<int>>& board, vector<vector<bool>>& vis){
        vis[i][j] = 1;
        if(i>0 && !vis[i-1][j]) {
            if(board[i-1][j] == 1)
                dfs(i-1, j, board, vis);
        }
        if(j>0 && !vis[i][j-1]) {
            if(board[i][j-1] == 1)
                dfs(i, j-1, board, vis);
        }
        if(i<board.size()-1 && !vis[i+1][j]) {
            if(board[i+1][j] == 1)
                dfs(i+1, j, board, vis);
        }
        if(j<board[i].size()-1 && !vis[i][j+1]) {
            if(board[i][j+1] == 1)
                dfs(i, j+1, board, vis);
        }
    }
};