class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(0, nums, ds, ans);
        return ans;
    }
    void helper(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
    {
        ans.push_back(ds);
        if(ind == nums.size()){
            return;
        }
        for(int i = ind; i<nums.size(); i++)
        {
            if(i>ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
};