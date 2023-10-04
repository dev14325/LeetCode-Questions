class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
       for(int ele : nums){
           if(m.find(ele)!=m.end()){
               ans+=m[ele];

           }

           m[ele]++;
       }

       return ans;


      
        
    }
};