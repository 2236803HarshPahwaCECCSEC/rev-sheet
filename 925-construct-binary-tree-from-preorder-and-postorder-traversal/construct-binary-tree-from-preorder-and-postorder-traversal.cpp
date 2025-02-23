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
    int pre_index=0;
    int post_index=0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* curr=new TreeNode(preorder[pre_index]);
        pre_index++;
        if(curr->val!=postorder[post_index]){
            curr->left=constructFromPrePost(preorder,postorder);
        }
        if(curr->val!=postorder[post_index]){
            curr->right=constructFromPrePost(preorder,postorder);
        }
        post_index++;
        return curr;
    }
};