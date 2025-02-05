class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(auto it:nums){
            mpp[it]++;
            if(mpp[it]==(nums.size()/3)+1)
                ans.push_back(it);
        }
        return ans;
    }
};