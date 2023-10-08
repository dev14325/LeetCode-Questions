class Solution {
public:
    int findMin(vector<int>& nums) {
          int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the last element, search in the right half.
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        // If the middle element is less than the last element, search in the left half.
        else if (nums[mid] < nums[right]) {
            right = mid;
        } 
        // If they are equal, move the right pointer to narrow down the search.
        else {
            right--;
        }
    }

    return nums[left];
    }
};