class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum=0;
        int cnt=0;
        mpp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            cnt+=mpp[sum-k];
            mpp[sum]++;
        }
        return cnt;
    }
};