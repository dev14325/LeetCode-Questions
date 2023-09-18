
class Solution {
public:
  int maxPathSum(TreeNode* root) {
    if (!root)
        return 0;

    int maxSum = INT_MIN;
    int n = 0; // Number of nodes in the tree

    // Helper function to calculate the maximum path sum starting from a given node
    function<int(TreeNode*)> maxPathSumFromNode = [&](TreeNode* node) {
        if (!node)
            return 0;

        int leftMax = maxPathSumFromNode(node->left);
        int rightMax = maxPathSumFromNode(node->right);

        int nodeMax = node->val;
        if (leftMax > 0)
            nodeMax += leftMax;
        if (rightMax > 0)
            nodeMax += rightMax;

        maxSum = max(maxSum, nodeMax);

        return max(node->val, max(leftMax, rightMax) + node->val);
    };

    // Calculate the maximum path sum considering all possible starting nodes
    function<void(TreeNode*)> calculateMaxPathSum = [&](TreeNode* node) {
        if (!node)
            return;

        maxPathSumFromNode(node); // Calculate max sum starting from this node

        calculateMaxPathSum(node->left);
        calculateMaxPathSum(node->right);

        n++; // Increment the count of nodes visited
    };

    calculateMaxPathSum(root);

    // Handle the case where all node values are non-negative
    if (n == 1)
        return maxSum;

    return maxSum;
}
};