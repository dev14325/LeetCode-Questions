class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool reverseOrder = false;

        while (!q.empty()) {
            int n = q.size();
            vector<int> curr(n);

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = reverseOrder ? n - 1 - i : i;
                curr[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(curr);
            reverseOrder = !reverseOrder;
        }

        return ans;
    }
};