class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(n==2) return nums[0]<nums[1]?1:0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int l=1, h=n-2;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]) {
                // In the Increasing half. So ans at right.
                l=mid+1;
            } else if(nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1]){
                // In the decreasing half. So ans at left
                h=mid-1;
            }
            else if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
            else h=mid-1; // Ans can be in both side. So discard any one half
        }
        return -1;
    }
};