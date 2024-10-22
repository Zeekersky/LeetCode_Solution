class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, ans, ds);
        return ans;
    }
    void helper(int ind, int target, vector<int>& cand, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);  
            return; 
        }
        for(int i = ind; i<cand.size(); i++)
        {
            if(i>ind && cand[i]==cand[i-1]) continue;
            if(cand[i]>target) break;
            ds.push_back(cand[i]);
            helper(i+1, target-cand[i], cand, ans, ds);
            ds.pop_back();
        }
    }
};