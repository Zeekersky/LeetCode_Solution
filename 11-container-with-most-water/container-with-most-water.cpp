class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, maxi=0;
        while(l<r){
            if(height[l]>height[r]){
                maxi = max(maxi, (r-l)*height[r--]);
            }
            else maxi = max(maxi, (r-l)*height[l++]);
        }
        return maxi;
    }
    // Recursion method -> dp will not help because of not overlapping subproblems.
    int maxArea1(vector<int>& height) {
        int ans1=0, ans2=0;
        // vector<vector<pair<int, int>>> dp(height.size(), vector<pair<int, int>>(height.size(), {-1, -1}));
        helper(0, height.size()-1, height, ans1, ans2); // , dp);
        return (ans2-ans1)*min(height[ans1], height[ans2]);
    }
    void helper(int l, int r, vector<int>& h, int& ans1, int& ans2){ //, vector<vector<pair<int, int>>>& dp){
        if(l>r || l<0 || l>=h.size() || r<0 || r>=h.size())
            return;
        // if(dp[l][r].first != -1 && dp[l][r].second!= -1){
        //     ans1 = dp[l][r].first;
        //     ans2 = dp[l][r].second;
        //     return;
        // }
        if((r-l)*min(h[l],h[r]) > (ans2-ans1)*min(h[ans1], h[ans2])){
            ans1 = l;
            ans2 = r;
            // dp[l][r] = {l, r};
        }
        helper(l+1, r, h, ans1, ans2); //, dp);
        helper(l, r-1, h, ans1, ans2); //, dp);
    }
};