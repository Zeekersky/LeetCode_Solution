class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> hash(256, {' ',0});
        for(int i=0; i<s.length(); i++)
        {
            hash[s[i]].first = s[i];
            hash[s[i]].second++;
        }
        
        sort(hash.begin(), hash.end(), comp);
        s = "";
        for(auto i: hash)
        {
            while(i.second!=0)
            {
                s+= i.first;
                i.second--;
            }
        }
        return s;
    }
    static bool comp(pair<char, int>& p1, pair<char, int>& p2)
    {
        return p1.second>p2.second;
    }
};