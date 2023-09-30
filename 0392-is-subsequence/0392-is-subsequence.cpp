class Solution {
public:
    bool isSubsequence(string s, string t) {

        int slen = s.length();
        int tlen = t.length();
        int i = 0;
        int j = 0;
        while(i<slen && j<tlen){
            if(s[i]==t[j]){
                i++;
            } 
            
                j++;
            
        }
        return i ==slen ;
        
    }
};