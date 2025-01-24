class Solution {
public:
    long long findh(vector<int>&piles,int mid){
        int n = piles.size();
        long long ans1 = 0;
        for(int i=0; i<n; i++){
            // ans1 += (piles[i]+mid-1) / mid;
            ans1 += (piles[i]/mid) + (piles[i]%mid>0?1:0);
        }
        return ans1;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int n = piles.size();
        int l = 1;
        int h = *max_element(piles.begin(),piles.end());
        long long ans =0;
        while(l<=h){
            int mid = l + (h-l)/2;
            ans=findh(piles,mid);
            if(ans<=hr) {
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};