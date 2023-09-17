class Solution 
{
public:
    std::vector<int> min_bins;
    int mincost(std::vector<int> &cost,int pos,int n)
    {
        // No weights at the end
        if(pos>n) return 0;
        if(min_bins[pos]!=-1) return min_bins[pos];
        int sum1 = cost[pos];
        sum1+= mincost(cost,pos+1,n);
        int sum2 = cost[pos];
        sum2 += mincost(cost,pos+2,n);
        return min_bins[pos]= std::min(sum1,sum2);
    }

    int minCostClimbingStairs(vector<int>& cost) 
    {
        if(cost.size()==2) return std::min(cost[0],cost[1]);
        int n = cost.size()-1; //max steps
        std::vector<int> min_bin(n+1,-1); 
        min_bins = std::move(min_bin);
        return std::min(mincost(cost,1,n), mincost(cost,0,n));
    }
};