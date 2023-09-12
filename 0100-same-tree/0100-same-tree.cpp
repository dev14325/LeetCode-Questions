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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        else if(p==NULL || q==NULL) return false;
        else{
            bool c1 = p->val==q->val;
            bool c2 = isSameTree(p->left,q->left);
            bool c3 = isSameTree(p->right,q->right);
            if(c1&&c2&&c3) return true;
            else return false;
        }

        return false;
        
    }
};