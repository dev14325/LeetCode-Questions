
class Solution {
public:
    TreeNode* minVal(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else { // Node with the key is found
            // 0 or 1 children case
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            // 2 children case
            TreeNode* temp = minVal(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};