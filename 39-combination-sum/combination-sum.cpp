class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, target, candidates, ans, ds);
        return ans;
    }
    void helper(int ind, int target, vector<int>& cand, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(ind==cand.size())
        {
            if(target == 0)
                ans.push_back(ds);
            return;
        }
        if(target >= cand[ind]){
            ds.push_back(cand[ind]);
            helper(ind, target-cand[ind], cand, ans, ds);
            ds.pop_back();
        }
        helper(ind+1, target, cand, ans, ds);
    }
};