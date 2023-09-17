class Solution {
public:
    int robber(int n,vector<int> &nums,vector<int> &val){
        
        if(n==0) return nums[n];
        if(n<0) return 0;

        if(val[n] != -1) return val[n];
        
        int first = nums[n] + robber(n-2,nums,val);
        int second = robber(n-1,nums,val);

        return val[n] = max(first,second);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> val(n,-1);

        return robber(n-1,nums,val);
        
    }
};