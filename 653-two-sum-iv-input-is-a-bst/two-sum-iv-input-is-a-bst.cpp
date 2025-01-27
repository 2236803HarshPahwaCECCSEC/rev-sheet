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
    void findinorder(TreeNode* root,vector<int> &inorder){
        if(root==nullptr) return;
        findinorder(root->left,inorder);
        inorder.push_back(root->val);
        findinorder(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        findinorder(root,inorder);
        int l=0;
        int r=inorder.size()-1;
        while(l<r){
            int sum=inorder[l]+inorder[r];
            if(sum==k) return true;
            if(sum<k) l++;
            if(sum>k) r--;
        }
        return false;
    }
};