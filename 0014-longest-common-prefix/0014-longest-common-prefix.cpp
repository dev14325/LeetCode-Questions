class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) {
        return "";  // If the input array is empty, return an empty string
    }

    // Iterate through the characters of the first string
    for (int i = 0; i < strs[0].size(); ++i) {
        char currentChar = strs[0][i];

        // Compare the current character with the same position in other strings
        for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != currentChar) {
                return strs[0].substr(0, i);  // Return the common prefix found so far
            }
        }
    }

    return strs[0]; 
    }
};