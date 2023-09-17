class Solution 
{
public:
 vector<vector<int>>ans;
    void help(int idx,vector<int>nums,vector<int>&v,int target,int size)
    {
        if(target<0)
        {
            return;
        }
        if(target==0&&v.size()==size)
        {
            if(v.size()==size)
            ans.push_back(v);            
            return ;
        }

        for(int i=idx;i<9&&nums[i]<=target;i++)
        {
            if(i==idx||nums[i]!=nums[i-1])
            {
                v.push_back(nums[i]);
                help(i+1,nums,v,target-nums[i],size);
                v.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum3(int size, int target) 
    {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>v;
        help(0,nums,v,target,size);
        return ans;
    }
};