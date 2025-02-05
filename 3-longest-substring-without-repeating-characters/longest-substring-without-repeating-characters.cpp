class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256, -1);
        int l = 0, r = 0, maxi = 0;
        while(r<s.length()) {
            if(arr[s[r]] != -1){
                l = max(arr[s[r]]+1, l);
            }
            arr[s[r]] = r;
            cout << "l: " << l << " r: " << r << endl;
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};