class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int l=i+1, r=nums.size()-1;
            while(l<r){
                int currSum = nums[l]+nums[r]+nums[i];
                int currDiff = abs(currSum-target);
                int calc = diff>currDiff?((ans=currSum)&&(diff=currDiff)):0;
                // if(diff>currDiff){
                //     ans = currSum;
                //     diff = currDiff;
                // }
                if(!diff) return ans;
                if(currSum <= target) l++;
                else r--;
            }
        }
        return ans;
    }
};