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

   vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool lToR = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> curr(n);
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                

                int idx = lToR ? i : n-1-i;
                curr[idx] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            

            }

            ans.push_back(curr);
            lToR =!lToR;
        }
        return ans;
        
    }
};