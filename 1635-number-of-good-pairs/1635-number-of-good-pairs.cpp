class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodpairs = 0;
        int counts[101] = {0}; //1<=nums[i]<=100
        for(int ele : nums){
            goodpairs+=counts[ele];
            counts[ele]++;
        }

        return goodpairs;
        
    }
};