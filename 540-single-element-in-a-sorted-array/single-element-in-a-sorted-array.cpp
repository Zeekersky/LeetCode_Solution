class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int l=1, h=n-2;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid-1] == nums[mid]){
                if(mid%2 == 1) // We are in Left half of ans
                    l=mid+1;
                else h=mid-1;
            }
            else if(nums[mid] == nums[mid+1]){
                if(mid%2 == 0) // We are in right half of ans
                    l=mid+1;
                else h=mid-1;
            }
            else return nums[mid];
        }
        return -1;
    }
};