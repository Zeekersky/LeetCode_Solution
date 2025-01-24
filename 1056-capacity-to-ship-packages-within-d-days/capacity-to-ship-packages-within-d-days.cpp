class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0, h=0;
        for(auto it:weights){
            h+=it;
            l=max(l, it);
        }

        int ans=0;
        while(l<=h){
            int mid = (l+h)/2;
            if(checkPossible(mid, weights, days)){
                ans = mid;
                h = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
    bool checkPossible(int midCap, vector<int>& weights, int days){
        int ansDays = 1, sum = 0;
        for(auto it:weights){
            sum += it;
            if(sum>midCap){
                ansDays++;
                sum = it;
            }
            if(ansDays>days) return 0;
        }
        return 1;
    }
};