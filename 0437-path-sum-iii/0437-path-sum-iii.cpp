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
 long long  temp(TreeNode* root, long long targetSum) {
        if (!root) {
            return 0LL; // Base case: Empty tree, no paths.
        }

        // Count paths starting from the current node.
        long long pathsFromRoot = temp2(root, targetSum);

        // Recursively count paths in left and right subtrees.
        long long pathsInLeftSubtree = temp(root->left, targetSum);
        long long  pathsInRightSubtree = temp(root->right, targetSum);

        // Total paths including the current node and those in subtrees.
        return pathsFromRoot + pathsInLeftSubtree + pathsInRightSubtree;
    }
    long long temp2(TreeNode* root, long long  targetSum) {
        if(root==NULL) return 0;
        long long cnt = 0LL;
        if(root->val==targetSum) cnt++;

       cnt += temp2(root->left,targetSum-root->val);
       cnt += temp2(root->right,targetSum-root->val);
        return cnt;
        
    }

    int pathSum(TreeNode* root,int targetSum){
        return temp(root,targetSum);

    }
};