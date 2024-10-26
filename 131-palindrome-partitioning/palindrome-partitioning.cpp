class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        helper(0,s,ds,ans);
        return ans;
    }
    void helper(int ind, string s, vector<string>& ds, vector<vector<string>>& ans)
    {
        if(ind==s.length())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<s.length(); i++)
        {
            if(isP(i, ind, s))
            {
                string temp = "";
                for(int j=ind; j<=i; j++)
                    temp += s[j];
                ds.push_back(temp);
                helper(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    bool isP(int i, int ind, string s)
    {
        while(ind<i)
        {
            if(s[i--]!=s[ind++])
                return false;
        }
        return true;
    }
};