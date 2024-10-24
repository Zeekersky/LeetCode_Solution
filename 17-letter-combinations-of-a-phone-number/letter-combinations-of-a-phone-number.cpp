class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ds;
        vector<string> ans;
        if(digits.length()==0) return ans;
        helper(0,digits, map, ds, ans);
        return ans;
    }
    void helper(int ind, string digits, vector<string>& map, string ds, vector<string>& ans)
    {
        if(ind == digits.length())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<map[digits[ind]-'0'].length(); i++)
        {
            ds+=map[digits[ind]-'0'][i];
            helper(ind+1, digits, map, ds, ans);
            ds.pop_back();
        }
    }
};