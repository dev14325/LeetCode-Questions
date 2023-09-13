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
        
        for(int i=0;i<n;i++){

      
        TreeNode* temp = q.front();

        if(i==n-1) curr.push_back(temp->val);
        
        
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