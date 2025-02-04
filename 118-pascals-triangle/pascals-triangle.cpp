class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            int col = i;
            vector<int> temp;
            while(col>0){
                temp.push_back(findNcR(i-1, i-col));
                col--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
    long long  findNcR(int n, int r){
        long long res = 1;
        for(int i=0; i<r; i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return res;
    }
};