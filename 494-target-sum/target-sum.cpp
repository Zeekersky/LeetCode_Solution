class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums.size()-1, nums, target);
    }
    int helper(int ind, vector<int>& nums, int target){
        // Base Case
        if(ind == -1){
            if(target == 0) return 1;
            else return 0;
        }
        int plus = helper(ind-1, nums, target-nums[ind]);
        int minus = helper(ind-1, nums, target+nums[ind]);
        return plus+minus;
    }
};