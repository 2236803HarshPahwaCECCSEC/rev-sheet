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
    vector<int>computeleafarray(TreeNode* root,vector<int>& checktree){
        if(root->left==NULL&& root->right==NULL) checktree.push_back(root->val);
        else{
            if(root->left)computeleafarray(root->left,checktree);
            if(root->right)computeleafarray(root->right,checktree);
        }
        return checktree;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> checktree1;
        vector<int> checktree2;
       computeleafarray(root1,checktree1);
       computeleafarray(root2,checktree2);
        return (checktree1==checktree2)?true:false;
    }
};