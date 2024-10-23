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
                stack<char> st;
                while(count!=0)
                {
                    int r = count % 10;
                    st.push(r+'0');
                    count = count / 10;
                }
                while(!st.empty()){
                    chars[update++] = st.top();
                    st.pop();
                    len++;
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