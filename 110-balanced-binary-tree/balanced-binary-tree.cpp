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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        int height=max(leftheight,rightheight)+1;
        return height;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        int diff=abs(leftheight-rightheight);
        bool checkheight=(diff<=1);
        bool checkleft=isBalanced(root->left);
        bool checkright=isBalanced(root->right);
        return (checkheight&&checkleft&&checkright)?true:false;
    }
};