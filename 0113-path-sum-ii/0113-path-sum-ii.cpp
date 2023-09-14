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

void getPath(TreeNode* root,int targetSum,vector<int> &res,vector<vector<int>> &ans){
   
    if(root==NULL) return;
    res.push_back(root->val);
    
    targetSum-=root->val;
    if(root->left==NULL && root->right==NULL && targetSum==0){
        ans.push_back(res);
       
    } 

    
    getPath(root->left,targetSum,res,ans) ;
    getPath(root->right,targetSum,res,ans);
    res.pop_back();
 
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<int> res;
       vector<vector<int>> ans;

       getPath(root,targetSum,res,ans);
       return ans;
        
    }
};