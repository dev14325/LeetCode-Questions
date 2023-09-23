
class Solution {
public:
  int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root)
        return 0;

    // Recursively calculate the maximum path sum for left and right subtrees
    int leftMax = max(maxPathSum(root->left, maxSum), 0);
    int rightMax = max(maxPathSum(root->right, maxSum), 0);

    // Calculate the maximum path sum that includes the current node as the highest point
    int currentMax = root->val + leftMax + rightMax;

    // Update the overall maximum path sum
    maxSum = max(maxSum, currentMax);

    // Return the maximum path sum that can be extended upward to the parent node
    return root->val + max(leftMax, rightMax);
}

int maxPathSum(TreeNode* root) {
    if (!root)
        return 0;

    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);

    return maxSum;
}
};