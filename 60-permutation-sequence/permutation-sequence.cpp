class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        vector<int> nums;
        for(int i=1; i<=n; i++)
            nums.push_back(i);
        helper(n, k-1, nums, s);
        return s;
    }
    void helper(int n, int k, vector<int> &nums, string &s){
        if(n==0)
            return;
        int fact = 1;
        for (int i = 1; i < n; ++i) {
            fact *= i;
        }
        int next = k/fact;
        if(next < nums.size())
            s+= to_string(nums[next]);
        nums.erase(nums.begin() + next);

        helper(n-1, k%fact, nums, s);
    }
};