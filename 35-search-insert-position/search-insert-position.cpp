class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
    int binarySearch(vector<int>& nums, int tar, int l, int h){
        if(l<=h){
            int mid = l+((h-l)/2);
            if(nums[mid] == tar) return mid;
            else if(nums[mid]>tar) return binarySearch(nums, tar, l, mid-1);
            else return binarySearch(nums, tar, mid+1, h);
        }
        return l;
    }
};