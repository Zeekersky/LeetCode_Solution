class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), hash(nums.size());
        int maxi = 1, lastIndex = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(maxi<dp[i]){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(nums.begin(), nums.end());
        return ans;
    }
};