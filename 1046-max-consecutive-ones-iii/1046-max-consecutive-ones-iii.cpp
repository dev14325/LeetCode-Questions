class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        

        int ans = 0;
        int maxi = 0;
        int i = 0, j = 0;
        int ct=0;

        while(j<nums.size()){

          if(nums[j]==1){
            j++;
            ans=j-i;
            maxi=max(ans,maxi);
            
          }
          else if(ct<k){
            j++;
            ans=j-i;
            maxi=max(ans,maxi);
            ct++;
          }

          else{
            if(nums[i]==0){
              ct--;
            }
            i++;
          }

        }

       
        return maxi;
    }
};
