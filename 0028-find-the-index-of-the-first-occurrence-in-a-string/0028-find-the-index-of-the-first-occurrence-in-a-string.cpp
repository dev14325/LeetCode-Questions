class Solution {
public:
    int strStr(string haystack, string needle) {
       
        int k = needle.size();
        int i=0;
        int j=0;
        string s = "";
        while(j<haystack.size()){
            s+=haystack[j];

            if(j-i+1<k) j++;
            else if(j-i+1==k) {
                if(s==needle) return i;
                 s.erase(s.begin());
                 i++;
                 j++;
            }
           


        }
         return -1;
        
    }
   
};