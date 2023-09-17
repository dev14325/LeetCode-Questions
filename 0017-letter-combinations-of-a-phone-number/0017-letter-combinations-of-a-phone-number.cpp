class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if (digits.empty()){
            return result;
        }
        vector<string>mapping={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string currcombo;
        helper(digits,mapping,0,currcombo,result);
        return result;
    }
    void helper(string digits, const vector<string>& mapping, int index, string& currcombo, vector<string>& result){
        if(index==digits.length()){
            result.push_back(currcombo);
            return;
        }
        int digit=digits[index]-'2';
        const string& letters=mapping[digit];
        for(char letter:letters){
            currcombo.push_back(letter);
            helper(digits,mapping,index+1,currcombo,result);
            currcombo.pop_back();
        }
    }
};