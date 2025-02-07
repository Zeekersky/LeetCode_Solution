class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int ind = INT_MAX;
        if(strs.size()==1) return strs[0]; 
        for(int s=0; s<strs.size()-1; s++){
            int i=-1;
            while((i+1)<min(strs[s].size(), strs[s+1].size()) && strs[s][i+1]==strs[s+1][i+1])
                i++;
            ind = min(ind, i);
            // cout << i << " " << ind << endl;
        }
        if(ind != INT_MAX)
            ans = strs[0].substr(0, ind+1);
        return ans;
    }
};