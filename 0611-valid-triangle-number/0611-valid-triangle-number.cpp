class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    // If nums[left] + nums[right] > nums[i], all combinations
                    // with nums[left], nums[right], and nums[i] are valid.
                    cnt += (right - left);
                    right--;
                } else {
                    // If nums[left] + nums[right] <= nums[i], move left to
                    // the right to increase the sum.
                    left++;
                }
            }
        }

        return cnt;
    }
};
