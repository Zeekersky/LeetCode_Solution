class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start == goal) return 0;
        int n = ceil(log2(start > goal ? start : goal) + 1);
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if((start&(1<<i)) != (goal&(1<<i)))
                count++;
        }
        return count;
    }
};