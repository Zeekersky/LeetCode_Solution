class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1, fl = -1, cl = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] == target){
                int ans1 = mid;
                while(ans1>=0 && nums[ans1]==target)
                    ans1--;
                int ans2 = mid;
                while(ans2<nums.size() && nums[ans2]==target)
                    ans2++;
                return {++ans1, --ans2};
            }
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        return {-1, -1};
    }
};