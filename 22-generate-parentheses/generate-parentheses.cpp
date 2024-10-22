class Solution {
public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        generateParenthesisEach(n, 0, 0, "", ans);
        return ans;
    }
public:
    void generateParenthesisEach(int n, int open, int close, string sol, vector<string>& ans) {
        if (sol.size() == 2 * n)
        {
            ans.push_back(sol);
            return;
        }
        if (open < n)
            generateParenthesisEach(n, open + 1, close, sol + "(", ans);
        if (close < open) //Maintaining the order of '(' and ')'
            generateParenthesisEach(n, open, close + 1, sol + ")", ans);
    }
};