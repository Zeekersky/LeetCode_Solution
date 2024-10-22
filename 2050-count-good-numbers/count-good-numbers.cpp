class Solution {
public:
    int countGoodNumbers(long long n) {
        // n/2+1 - even pos, n/2 - odd pos
        if(n%2 == 0)
            return int(binaryExp(20, n/2));
        else return int(5*binaryExp(20, (n-1)/2)%1000000007);
    }
private:
    long binaryExp(long x, long long n) {
        if (n == 0) {
            return 1;
        }
        int M = 1000000007;
        if (n % 2 == 1) {
            return (x * binaryExp((x * x)%M, (n - 1) / 2) % M);
        } else {
            return binaryExp((x * x)%M, n / 2);
        }
    }
};