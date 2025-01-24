class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1, h=0;
        for(auto it:bloomDay) h=max(h, it);

        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(checkPossible(mid, bloomDay, k, m)){
                ans = mid;
                h = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
    bool checkPossible(int mid, vector<int>& bloomDay, int k, int m){
        int adjCount = 0, ans = 0;
        for(auto it:bloomDay){
            if(it<=mid) adjCount++;
            else adjCount=0;

            if(adjCount==k){
                ans++;
                adjCount = 0;
            }
            if(ans>=m) return 1;
        }
        return 0;
    }
};