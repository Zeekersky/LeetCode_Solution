class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> ds(n, s);
        helper(0, n, ds, ans);
        return ans;
    }
    void helper(int col, int n, vector<string>& ds, vector<vector<string>>& ans)
    {
        if(col == n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(safe(i, col, n, ds)){
                ds[i][col] = 'Q';
                helper(col+1, n, ds, ans);
                ds[i][col] = '.';
            }
        }
    }
    bool safe(int row, int col, int n, vector<string>& board)
    {
        int row1 = row;
        int col1 = col;
        // checking left direction
        while(col1>=0)
        {
            if(board[row1][col1]=='Q')
                return false;
            col1--;
        }
        col1=col;
        // checking top left direction
        while(col1>=0 && row1>=0)
        {
            if(board[row1][col1]=='Q')
                return false;
            col1--;
            row1--;
        }
        col1 = col;
        row1 = row;
        // checking bottom left direction
        while(col1>=0 && row1<n)
        {
            if(board[row1][col1]=='Q')
                return false;
            col1--;
            row1++;
        }
        return true;
    }
};