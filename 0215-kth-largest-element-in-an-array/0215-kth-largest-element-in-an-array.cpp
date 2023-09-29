class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      multiset<int> s;
      for(int ele : nums){
          s.insert(ele);
          if(s.size()>k){
              s.erase(s.begin());
          }
      }
    
    return *s.begin();
}
};

