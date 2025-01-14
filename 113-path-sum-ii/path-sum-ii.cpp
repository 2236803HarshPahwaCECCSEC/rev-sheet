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
    void solve(TreeNode* root,int targetSum,vector<vector<int>>&res,vector<int>temp,int sum) {
        if(root==nullptr) return;
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            if(sum==targetSum)res.push_back(temp);
        }
        solve(root->left,targetSum,res,temp,sum);
        solve(root->right,targetSum,res,temp,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<vector<int>> res;
        vector<int> temp;
        solve(root,targetSum,res,temp,sum);
        return res;
    }
};