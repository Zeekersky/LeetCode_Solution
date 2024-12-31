class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int target = 0;
        for(int i=0; i<arr.size(); i++){
            target+= arr[i];
        }
        if(target - d < 0 || (target-d)%2) return 0;
        target = (target - d)/2;
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        if(arr[0]==0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0]!=0 && arr[0]<= target) prev[arr[0]] = 1;
        curr[0] = 1;
        for(int i=1; i<arr.size(); i++){
            for(int j=0; j<=target; j++){
                int pick = 0;
                if(arr[i]<=j) pick = prev[j-arr[i]];
                int notPick = prev[j];
                curr[j] = pick + notPick;
            }
            prev = curr;
        }
        int ans = prev[target];
        return ans;
    }
};