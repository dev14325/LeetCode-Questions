class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         auto left = std::lower_bound(nums.begin(), nums.end(), target);
    auto right = std::upper_bound(nums.begin(), nums.end(), target);

    if (left == nums.end() || *left != target) {
        return {-1, -1};
    }

    return {static_cast<int>(std::distance(nums.begin(), left)), static_cast<int>(std::distance(nums.begin(), right - 1))};
        
    }
};