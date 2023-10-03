class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        stack<char> st;
        string s1 ="";
        for(char c : s){
            st.push(c);

        }

        while(!st.empty()){
            char ch = st.top();
            s1+=ch;
            st.pop();
        }

        return (s==s1);
        
    }
};