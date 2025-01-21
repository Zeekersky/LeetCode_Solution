class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] == target) return mid;
            if(nums[l]<=nums[mid]){ // Left Portion Sorted
                if(nums[l] <= target && target <= nums[mid])
                // if target resides in between sorted portion
                    h = mid-1;
                else l = mid + 1;
            }
            else{ // Right portion sorted
                if(nums[mid] <= target && target <= nums[h])
                // if target resides in between sorted portion
                    l = mid+1;
                else h = mid-1;
            }
        }
        return -1;
    }
};