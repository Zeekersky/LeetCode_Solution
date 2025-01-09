class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return helper(0, arr, k, dp);
    }
    int helper(int start, vector<int>& arr, int k, vector<int>& dp){
        // Base Case
        if(start == arr.size()) return 0;
        if(dp[start] != -1) return dp[start];
        int maxi = 0, maxEle = arr[start];
        for(int l=start; l< min(start+k, (int) arr.size()); l++){
            if(maxEle < arr[l]) maxEle = arr[l];
            int steps = maxEle*(l-start+1) + helper(l+1, arr, k, dp);
            maxi = max(maxi, steps);
        }
        return dp[start] = maxi;
    }
};