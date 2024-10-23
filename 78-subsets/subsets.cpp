class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0,nums, ds, ans);
        return ans;
    }
    void helper(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
    {
        if(ind == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        helper(ind+1, nums, ds, ans);
        ds.pop_back();
        helper(ind+1, nums, ds, ans);
    }
};