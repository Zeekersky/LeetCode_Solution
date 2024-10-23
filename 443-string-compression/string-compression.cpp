class Solution {
public:
    int compress(vector<char>& chars) {
        int ind = 1, len = 1, update = 1;
        if(chars.size()==1) return 1;
        while(ind<chars.size())
        {
            if(chars[ind] == chars[ind-1])
            {
                int count = 1;
                while(ind<chars.size() && chars[ind]==chars[ind-1]){
                    ind++;
                    count++;
                }
                cout << chars[ind-1] << " " << count << endl;
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[update++] = c;
                        len++;
                    }
                }
                if(ind+1<chars.size()) {
                    chars[update++] = chars[ind];
                    ind++;
                    len++;
                }
            }
            else {
                len++;
                chars[update++] = chars[ind];
                ind++;
            }
        }
        return len;
    }
};