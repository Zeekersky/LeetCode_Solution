class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool helper(int row, int col, vector<vector<char>>& board, const string& word, int ind) {
        if (ind == word.size()) 
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[ind]) 
            return false;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = helper(row + 1, col, board, word, ind + 1) ||
                     helper(row - 1, col, board, word, ind + 1) ||
                     helper(row, col + 1, board, word, ind + 1) ||
                     helper(row, col - 1, board, word, ind + 1);

        board[row][col] = temp;

        return found;
    }
};
