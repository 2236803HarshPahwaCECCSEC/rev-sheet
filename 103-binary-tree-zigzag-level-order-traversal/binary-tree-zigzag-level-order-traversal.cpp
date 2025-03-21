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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> zigzag;
       
       if(root==nullptr) return zigzag;
       queue<TreeNode*>q;
       bool val=1;
       q.push(root);
       while(!q.empty()){
            vector<int>v;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                v.push_back(node->val);
            }
            if(val==1){
                zigzag.push_back(v);
                val=0;
            }else{
                reverse(v.begin(),v.end());
                zigzag.push_back(v);
                val=1;
            }
       }
       return zigzag;
    }
};