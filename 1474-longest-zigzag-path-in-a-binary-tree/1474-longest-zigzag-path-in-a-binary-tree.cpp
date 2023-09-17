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

    void check(TreeNode *root, int direction,int curr,int &counter)
    {
        if(root==NULL)
        {
            // int temp=curr;
            if(curr-1>counter)
            counter=curr-1;
            return;
        }
        // int t1=root->val,t2=curr;
        if(direction==1)
        {
            check(root->left,-1,curr+1,counter);
        }
        else
        {
            check(root->right,1,curr+1,counter);
        }
    }

    void inorder(TreeNode *root,int &counter)
    {
        if(root==NULL)
        return;
        
        inorder(root->left,counter);
        int temp=root->val;
        check(root,1,0,counter);
        check(root,-1,0,counter);
        inorder(root->right,counter);
    }

    
    int longestZigZag(TreeNode* root) {
        int counter=0;
        inorder(root,counter);
        return counter;
    }
};