/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);
    }
    
    int countGoodNodes(TreeNode* node, int maxVal) {
        if (node == nullptr) {
            return 0;
        }
        
        // If the current node's value is greater than or equal to the maximum value encountered
        // on the path from the root to this node, it is considered a good node.
        int goodNodeCount = (node->val >= maxVal) ? 1 : 0;
        
        // Update the maximum value encountered so far on the path.
        maxVal = max(maxVal, node->val);
        
        // Recursively traverse the left and right subtrees.
        goodNodeCount += countGoodNodes(node->left, maxVal);
        goodNodeCount += countGoodNodes(node->right, maxVal);
        
        return goodNodeCount;
    }
};
