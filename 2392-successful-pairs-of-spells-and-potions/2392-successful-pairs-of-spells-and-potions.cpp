class Solution {
public:
    int upper(vector<int>&arr,long long tar)
    {
        int s=0;
        int e=arr.size()-1;

        int mid=s+(e-s)/2;

        int ans=-1;

        while(s<=e)
        {
            if(arr[mid]>=tar)
            {
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());

        vector<int>ans;

        for(auto it:spells)
        {
            long long x=success/it;
            
            if(success%it!=0)
            x++;

            int k=upper(potions,x);
            
            if(k==-1)
            ans.push_back(0);
            else
            ans.push_back(potions.size()-k);
        }

        return ans;
    }
};