class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        return inorder(root, res);
    }

    bool inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return true;

        if (!inorder(root->left, res)) return false;

        if (!res.empty() && root->val <= res.back()) return false;

        res.push_back(root->val);

        if (!inorder(root->right, res)) return false;

        return true;
    }
};
