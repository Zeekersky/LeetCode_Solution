class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==1) return true;
        if(n<=0) return false;
        int count = 0;
        for(int i=0; i<ceil(log2(n)+1); i++)
        {
            if(n&(1<<i))
                count++;
            if(count>1)
                return false;
        }
        return true;
    }
};