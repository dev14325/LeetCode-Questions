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
    vector<int> rightSideView(TreeNode* root) {
          vector<int> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
      
        while(!q.empty()){
        int n = q.size();
        vector<int> curr;
        
        while(n--){
        TreeNode* temp = q.front();
        curr.push_back(temp->val);
        q.pop();
           
           
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);


        }
        ans.push_back(curr);
        }
        

      

      for(auto vec : ans){
          if(!vec.empty()){
              res.push_back(vec.back());
          }
      }

      return res;
    }
};