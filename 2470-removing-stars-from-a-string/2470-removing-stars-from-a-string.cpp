class Solution {
public:
    string removeStars(string s) {
        string a;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '*'){
                a.pop_back();
            }
            else{
                a.push_back(s[i]);
            }
        }

        return a;
    }
};