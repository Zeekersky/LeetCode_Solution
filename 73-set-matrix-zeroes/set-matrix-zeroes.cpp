class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>> mark(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    mark[i][j] = 1;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(mark[i][j]){
                    setrow(matrix, i, j);
                    setcol(matrix, i, j);
                }
            }
        }
    }
    void setrow(vector<vector<int>>& matrix, int row, int col){
        for(int i=0; i<matrix[row].size(); i++){
            matrix[row][i] = 0;
        }
    }
    void setcol(vector<vector<int>>& matrix, int row, int col){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }
};