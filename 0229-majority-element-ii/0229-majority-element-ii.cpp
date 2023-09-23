class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
      int d = n/3;
      unordered_map<int,int> m;
      for(int i=0;i<n;i++){
          m[nums[i]]++;
      } 

      for(auto ele : m){
          if(ele.second>d){
              res.push_back(ele.first);

          }
      }
      return res;


        
    }
};