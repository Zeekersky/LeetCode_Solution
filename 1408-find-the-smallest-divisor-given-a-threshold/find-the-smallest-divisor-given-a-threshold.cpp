class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, h=0;
        for(auto it:nums) h=max(h, it);

        int ans=-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(checkPossible(mid, nums, threshold)){
                ans = mid;
                h = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
    bool checkPossible(int mid, vector<int>& nums, int threshold){
        int ans=0;
        for(auto it:nums){
            ans+=it/mid + (it%mid>0?1:0);
            if(ans>threshold) return 0;
        }
        return 1;
    }
};