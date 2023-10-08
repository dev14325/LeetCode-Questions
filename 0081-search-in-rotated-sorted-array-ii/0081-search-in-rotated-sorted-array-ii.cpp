class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int ele : nums){
            if(ele==target) return true;
        }

        return false;
    }
};