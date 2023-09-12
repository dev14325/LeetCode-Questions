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

  int Height(TreeNode* root){
      if(root==NULL) return 0;
      int l = Height(root->left);
      int r = Height(root->right);

      return max(l,r)+1;
  }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        bool diff = abs(Height(root->left)-Height(root->right))<=1;
        if(l&& r&& diff){
            return true;
        }
        else return false;
        
    }
};