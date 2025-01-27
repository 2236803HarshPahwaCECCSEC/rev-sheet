class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root == nullptr) return -1;

        int leftans = kthSmallest(root->left, k);
        if(leftans != -1) return leftans;

        k--;
        if(k == 0) return root->val;

        return kthSmallest(root->right, k);
    }
};
