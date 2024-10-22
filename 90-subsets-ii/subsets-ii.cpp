class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> ds;
        helper(0, nums, ds, ans);
        vector<vector<int>> ans1;
        for(auto i:ans)
            ans1.push_back(i);
        return ans1;
    }
    void helper(int ind, vector<int>& nums, vector<int>& ds, set<vector<int>>& ans)
    {
        if(ind == nums.size()){
            ans.insert(ds);
            return;
        }
        ds.push_back(nums[ind]);
        helper(ind+1, nums, ds, ans);
        ds.pop_back();
        helper(ind+1, nums, ds, ans);
    }
};