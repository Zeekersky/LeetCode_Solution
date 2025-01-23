class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, h=nums.size()-1;
        while(l<h)
        {
            int mid = (l + h) / 2;
            // Check if mid is the minimum
            if (nums[mid] > nums[h])
                l = mid + 1; // Minimum is in the right half
            else
                h = mid; // Minimum is in the left half or at mid
        }
        return nums[l];
    }
};