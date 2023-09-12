class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightViewDFS(root, result, 0);
        return result;
    }

    void rightViewDFS(TreeNode* node, vector<int>& result, int depth) {
        if (!node) {
            return;
        }

        // If this is the first node encountered at the current depth, add it to the result.
        if (depth == result.size()) {
            result.push_back(node->val);
        }

        // Recursively traverse the right subtree first (rightmost node at each level).
        rightViewDFS(node->right, result, depth + 1);
        rightViewDFS(node->left, result, depth + 1);
    }
};
