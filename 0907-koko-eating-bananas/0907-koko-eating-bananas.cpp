class Solution {
public:
    int hrs(vector<int> & vec, int k){
        if(k==0) return INT_MAX;
        int hr=0,t=0;
        for(int i=0;i<vec.size();i+=1){
            t=vec[i]%k;
            if(t==0)
            hr+=vec[i]/k;
            else
            hr+=vec[i]/k+1;
        }
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=INT_MIN,i=0,j=0,mid=0,ans=INT_MAX;
        for(i=0;i<piles.size();i+=1)
         mx=max(piles[i],mx);
        i=0;j=mx;
        while(i<j+1){
            mid=(i+j)/2;
            if(hrs(piles,mid)>h)
            i=mid+1;
            else{
                ans=mid;
                j=mid-1;
            }
        }        
        return ans;
    }
};