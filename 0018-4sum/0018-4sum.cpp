class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n - 3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicate i values
            for(int j = i + 1; j < n - 2; j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;  // Skip duplicate j values
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j + 1, high = n - 1;
                while(low < high){
                    int sum = nums[low] + nums[high];
                    if (sum < newTarget)
                        low++;
                    else if (sum > newTarget)
                        high--;
                    else {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) low++; // Skip duplicate low values
                        while (low < high && nums[high] == nums[high - 1]) high--; // Skip duplicate high values
                        low++;
                        high--;
                    }
                }
            }
        }
        return res;
    }
};