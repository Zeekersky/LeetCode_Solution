class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum=0;
        int cnt=0;
        mpp[0] = 1;
        for(auto it:nums){
            sum+=it;
            cnt+=mpp[sum-k];
            mpp[sum]++;
        }
        return cnt;
    }
};