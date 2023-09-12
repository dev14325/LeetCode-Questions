// Define a comparison function to sort intervals based on their second element.
bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        // Sort the intervals based on their second elements using the custom comparison function.
        sort(nums.begin(), nums.end(), compareSecondElement);
        
        int ans = 0;     // Initialize a variable to store the answer.
        int k = INT_MIN; // Initialize a variable to keep track of the end of the last selected interval.
        
        // Iterate through the sorted intervals.
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i][0]; // Start of the current interval.
            int y = nums[i][1]; // End of the current interval.
            
            // If the start of the current interval is greater than or equal to the end of the last selected interval,
            // update the end of the last selected interval to the end of the current interval.
            if (x >= k) {
                k = y;
            } 
            // If there is an overlap, increment the answer counter.
            else {
                ans++;
            }
        }

        return ans; // Return the minimum number of intervals to remove.
    }
};