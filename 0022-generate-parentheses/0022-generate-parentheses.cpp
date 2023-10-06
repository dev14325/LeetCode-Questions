class Solution {
public:
    void generateParenthesis(vector<string> &ans, string temp,int open,int close,int n) {
        if(temp.size() == 2*n) {
            ans.push_back(temp);
            return;
        }
        if(open<n) {
            generateParenthesis(ans, temp+"(", open+1, close, n);
        }
        if(close<open) {
            generateParenthesis(ans, temp+")", open, close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        generateParenthesis(ans, temp, 0, 0, n);
        return ans;
    }
};