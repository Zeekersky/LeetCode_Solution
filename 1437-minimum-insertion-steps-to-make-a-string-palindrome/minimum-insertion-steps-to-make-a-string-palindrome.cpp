class Solution {
public:
    int minInsertions(string s) {
        string text1 = s;
        string text2 = "";
        for(int i=s.size()-1; i>=0; i--)
            text2+=s[i];
        vector<int> prev(s.size()+1, 0), curr(s.size()+1, 0);
        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1]==text2[j-1])
                    curr[j] = 1+prev[j-1];
                else
                    curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return s.size() - prev[text2.size()];
    }
};