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
    bool solve(TreeNode* root,int targetSum,int sum){
        if(root==nullptr) return false;
        sum+=root->val;
        if(root->left==nullptr&&root->right==nullptr){
            return (targetSum==sum);
        }
        bool leftans=solve(root->left,targetSum,sum);
        bool rightans=solve(root->right,targetSum,sum);
        return leftans|| rightans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool res=solve(root,targetSum,sum);
        return res;
    }
};