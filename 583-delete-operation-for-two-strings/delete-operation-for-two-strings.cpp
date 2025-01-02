class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs = LCS(word1, word2);
        return (word1.size()+word2.size()-2*lcs);
    }
    int LCS(string &text1, string &text2){
        vector<int> prev(text2.size(), 0), curr(text2.size(), 0);
        if(text1[0]==text2[0]) prev[0] = 1;
        for(int j=1; j<text2.size(); j++){
            prev[j] = max((text1[0] == text2[j] ? 1 : 0), prev[j-1]);
        }
        for(int i=1; i<text1.size(); i++){
            curr[0] = max((text1[i] == text2[0] ? 1 : 0), prev[0]);
            for(int j=1; j<text2.size(); j++){
                if(text1[i]==text2[j])
                    curr[j] = 1+prev[j-1];
                else
                    curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
        }
        return prev[text2.size()-1];
    }
};