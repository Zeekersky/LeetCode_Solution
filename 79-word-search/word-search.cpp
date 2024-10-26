class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        // Try to find the word starting from every cell in the board.
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (helper(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool helper(int row, int col, vector<vector<char>>& board, const string& word, int index) {
        if (index == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = helper(row + 1, col, board, word, index + 1) ||
                     helper(row - 1, col, board, word, index + 1) ||
                     helper(row, col + 1, board, word, index + 1) ||
                     helper(row, col - 1, board, word, index + 1);

        board[row][col] = temp;

        return found;
    }
};
