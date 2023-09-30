class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        for(int val : nums){
            if(val%2==0){
                res.push_back(val);
            }
        }

         for(int val : nums){
            if(val%2!=0){
                res.push_back(val);
            }
        }

        return res;

        
    }
};