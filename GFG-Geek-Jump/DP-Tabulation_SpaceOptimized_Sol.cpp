class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here
        if (n <= 1)
            return 0;
        int prev2 = 0, prev1 = abs(height[1] - height[0]), curri;
        if (n == 2)
            return prev1;
        for (int i = 2; i < n; i++)
        {
            curri = min(prev1 + abs(height[i] - height[i - 1]),
                        prev2 + abs(height[i] - height[i - 2]));
            prev2 = prev1;
            prev1 = curri;
        }
        return curri;
    }
};