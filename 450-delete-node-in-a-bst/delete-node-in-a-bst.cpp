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
    int maxinTree(TreeNode* root){
        if(root==NULL) return 0;
        TreeNode* temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key){//fourcases
            if(root->left==nullptr&&root->right==nullptr) {//if(root ke left right kuch na ho)
                delete root;
                return nullptr;
            }else if(root->left!=nullptr&& root->right==nullptr){
                TreeNode* leftsubtree=root->left;
                delete root;
                return leftsubtree;
            }else if(root->right!=nullptr&& root->left==nullptr){
                TreeNode* rightsubtree=root->right;
                delete root;
                return rightsubtree;
            }else{
                int maxval=maxinTree(root->left);
                root->val=maxval;
                root->left=deleteNode(root->left,maxval);
                return root;
            }
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
    return root;
    }
};