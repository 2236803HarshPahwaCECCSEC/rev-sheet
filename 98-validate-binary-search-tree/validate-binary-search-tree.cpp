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
 #include <climits>
class Solution {
public:
bool checkcondition(TreeNode* root,long long left,long long right){
    if(root==NULL) return true;
    bool condtn1= (root->val > left && root->val < right);
    bool leftkaans=checkcondition(root->left,left,root->val);
    bool rightkaans=checkcondition(root->right,root->val,right);
    
    return (condtn1&& leftkaans && rightkaans);
}
    bool isValidBST(TreeNode* root) {

        return checkcondition(root,LONG_MIN,LONG_MAX);
    }
};