class Solution {
public: 
    int solve(int i,int n,vector<int> &cost,vector<int> &time ,vector<vector<int > > &dp) 
    {    
        if( n<=0) 
        { 
            return 0;
        } 
        if(i<0) 
        { 
            return 1e9;
        }
        
        if(dp[i][n]!=-1) 
        { 
            return dp[i][n];
        }  
        //teke 
        int take=cost[i]+solve(i-1,n-1-time[i],cost,time,dp); 
        int nit=0+solve(i-1,n,cost,time,dp); 
        return dp[i][n]=min(take,nit);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
          
        vector<vector<int> > dp(cost.size(),vector<int> (cost.size()+1,-1)); 
        int n=cost.size();
         return solve(n-1,n,cost,time,dp);
    }
};