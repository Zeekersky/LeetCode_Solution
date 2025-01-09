class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // vector<int> dp(arr.size(), -1);
        // return helper(0, arr, k, dp);
        return tabulation(arr, k);
    }
    int tabulation(vector<int>& arr, int k){
        vector<int> dp(arr.size()+1, 0);
        for(int i=arr.size()-1; i>=0; i--){
            int maxi = 0, maxEle = arr[i];
            for(int l=i; l< min(i+k, (int) arr.size()); l++){
                if(maxEle < arr[l]) maxEle = arr[l];
                int steps = maxEle*(l-i+1) + dp[l+1];
                maxi = max(maxi, steps);
            }
            dp[i] = maxi;
        }
        return dp[0];
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