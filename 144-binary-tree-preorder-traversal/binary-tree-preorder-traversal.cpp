class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traverse;
        traversal(root, traverse); // Pass by reference
        return traverse;
    }
    void traversal(TreeNode* root, vector<int>& traverse) { // Pass by reference here
        if (root != nullptr) {
            traverse.push_back(root->val);
            if (root->left) traversal(root->left, traverse);
            if (root->right) traversal(root->right, traverse);
        }
    }
};
