class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1, cnt = 1, ele = nums[0];
        for(int i=0; i<nums.size()-1; i++){
            if(ele==nums[i+1]) continue;
            if(++ele==nums[i+1]){
                cnt++;
                ans = max(cnt, ans);
            }
            else{
                ele = nums[i+1];
                cnt = 1;
            }
        }
        return ans;
    }
};