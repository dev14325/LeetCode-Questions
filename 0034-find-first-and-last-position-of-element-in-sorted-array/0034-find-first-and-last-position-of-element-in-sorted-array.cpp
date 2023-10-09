class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        

       auto l = lower_bound(nums.begin(),nums.end(),target);
       auto u = upper_bound(nums.begin(),nums.end(),target);

       if(l==nums.end() ||  *l!=target) return {-1,-1};

      int idx1 = distance(nums.begin(),l);
      int idx2 = distance(nums.begin(),u-1);

      return {idx1,idx2};
    }
};