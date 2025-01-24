class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=0;
        for(auto it:piles) high=max(high, it);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(checkPossible(mid, piles, h)){
                ans = mid;
                high = mid-1;
            } else low = mid+1;
        }
        return ans;
    }
    bool checkPossible(int mid, vector<int>& piles, int h){
        int ans = 0;
        for(auto it:piles){
            ans += (it/mid) + (it%mid>0?1:0);
            if(ans>h) return 0;
        }
        return 1;
    }
};