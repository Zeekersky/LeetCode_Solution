class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here
        return helper(n - 1, height);
    }
    int helper(int ind, vector<int> &height)
    {
        if (ind <= 0)
            return 0;
        if (ind == 1)
            return abs(height[1] - height[0]);
        return min(helper(ind - 1, height) + abs(height[ind - 1] - height[ind]),
                   helper(ind - 2, height) + abs(height[ind - 2] - height[ind]));
    }
};