class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> subsetSum;
        vector<int> subset;
        helper(1, k, n, subsetSum, subset);
        return subsetSum;
    }
    void helper(int ind, int k, int n, vector<vector<int>>& subsetSum, vector<int>& subset)
    {
        if(n==0)
        {
            if(k==0)
                subsetSum.push_back(subset);
            return;
        }
        if(k<0||n<0||ind>9) return;
        if(n>=ind){
            subset.push_back(ind);
            helper(ind+1, k-1, n-ind, subsetSum, subset);
            subset.pop_back();
        }
        helper(ind+1, k, n, subsetSum, subset);
    }
};