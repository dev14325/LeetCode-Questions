class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int delid = -1, max = 0;
        while(j < nums.size()){
            if(nums[j] == 0){
                if(delid != -1){
                    i = delid + 1;
                }
                delid = j;
            }
            max = (max > j - i) ? max : j - i;
            j++;
        }
        return max;
    }
};