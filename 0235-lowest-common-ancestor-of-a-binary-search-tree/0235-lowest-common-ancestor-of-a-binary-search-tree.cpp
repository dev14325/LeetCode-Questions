/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

bool getPath(TreeNode* root,vector<TreeNode*> &ans,TreeNode* node){
       if(root==NULL) return false;
       ans.push_back(root);
       
       if(root->val==node->val) return true;

       if(getPath(root->left,ans,node) || getPath(root->right,ans,node)) return true;

       ans.pop_back();
       return false;
   }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;

      if(!getPath(root,v1,p) || !getPath(root,v2,q)) return NULL;

      TreeNode* lca = NULL;

      int l = min(v1.size(),v2.size());
      for(int i=0;i<l;i++){
          if(v1[i]==v2[i]) {
              lca = v1[i];
          }
          else {
              break;
          }
      }

      return lca;
        
    }
};