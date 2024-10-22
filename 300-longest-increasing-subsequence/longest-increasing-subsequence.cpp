class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            if(val <= temp.back()) {
                int idx = lower_bound(temp.begin(), temp.end(), val) - temp.begin();
                temp[idx] = val;
            } else {
                temp.push_back(val);
            }
        }
        return temp.size();
    }
};