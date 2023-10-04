class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<long long> pq;
        for (auto i:nums) pq.push(-1ll*i);
        int ans{1};
        while (pq.size()>0){
            long long i{-1ll*pq.top()};
            pq.pop();
            if (i>(long long)ans) return ans;
            else if (i==(long long)ans) ans++;
        }
        return ans;
    }
};