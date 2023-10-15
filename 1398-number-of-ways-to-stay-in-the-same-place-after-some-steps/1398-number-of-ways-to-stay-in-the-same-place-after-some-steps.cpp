class Solution {
public:
    int arr;
    map<pair<int,int>,int> dp;
    int f(int i,int s){
        if(s==0){
            return i==0;
        }

        if(dp.find({i,s})!=dp.end()) return dp[{i,s}];

        long long l=0,r=0,c=0;

        if(i>0) l+=f(i-1,s-1)%(int)(1e9+7);
        if(i<arr-1) r+=f(i+1,s-1)%(int)(1e9+7);
        c+=f(i,s-1)%(int)(1e9+7);

        return dp[{i,s}]=((l+r+c)%(long long)(1e9+7));
    }
    int numWays(int steps, int arrLen) {
        arr=arrLen;
        dp.clear();
        return f(0,steps);
    }
};