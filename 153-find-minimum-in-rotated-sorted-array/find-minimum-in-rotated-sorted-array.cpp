class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, h=nums.size()-1, ans=INT_MAX;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[l]<=nums[mid]){ // Left Portion Sorted
                ans = min(ans, nums[l]);
                l = mid+1;
            }
            else{ // Right portion sorted
                ans=min(ans, nums[mid]);
                h = mid-1;
            }
        }
        return ans;
    }
};