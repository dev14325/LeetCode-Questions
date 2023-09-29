class BSTIterator {
    
    stack<TreeNode*> s;
    bool reverse;

    public:

    BSTIterator (TreeNode* root, bool reverse) {
        this -> reverse = reverse;
        pushAll(root);
    }

    int next() {
        TreeNode* current = s.top();
        s.pop();
        if (!reverse) {
            pushAll(current -> right);
        } else {
            pushAll(current -> left);
        }
        return current -> val;
    }

    bool hasNext() {
        return !s.empty();
    }

    private:

    void pushAll(TreeNode* root) {
        for (; root; ) {
            s.push(root);
            if (!reverse) {
                root = root -> left;
            } else {
                root = root -> right;
            }
        }
    }

};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next(), j = r.next();

        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }

        return false;

    }
};