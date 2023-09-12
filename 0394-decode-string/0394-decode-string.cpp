class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        
        for(auto ch : s) {
            
            if(ch == ']') {
                string temp = "";
                
                while(st.empty() == false && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                
                reverse(temp.begin(), temp.end());
                st.pop();
                string count = "";
                
                while(st.empty() == false && st.top() >= '0' && st.top() <= '9') {
                    count = st.top() + count;
                    st.pop();
                }
                
                string ttemp = "";
                for(int i=1; i<=stoi(count); ++i)
                    ttemp += temp;

                for(int i=0; i<ttemp.size(); ++i) {
                    st.push(ttemp[i]);
                }
            } else {
                st.push(ch);
            }
        }
        
        string ans = "";
        
        while(st.empty() == false) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};