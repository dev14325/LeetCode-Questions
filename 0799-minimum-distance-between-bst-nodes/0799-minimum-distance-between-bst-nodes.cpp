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

   int findMinDiff(vector<int> &v){
       if(v.size()<2) return -1;

  
       sort(v.begin(),v.end());
       int minDiff = INT_MAX;
       for(int i=1;i<v.size();i++){
           int diff = v[i]-v[i-1];
           if(diff<minDiff){
               minDiff = diff;
           }
       }
       return minDiff;
   }
    vector<int> ans;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            for(int i=0;i<n;i++){ 
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            } 
             for(auto ele : curr){
                 ans.push_back(ele);
             }
            
        }
        return findMinDiff(ans);
       
       

       
        
    }
};