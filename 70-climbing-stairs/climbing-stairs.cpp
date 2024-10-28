class Solution {
public:
    int climbStairs(int n) {
        int prev=1, prev2=1, curri;
        if(n<=1) return 1;
        for(int i=2;i<=n;i++)
        {
            curri = prev+prev2;
            prev2 = prev;
            prev = curri;
        }
        return curri;
    }
};