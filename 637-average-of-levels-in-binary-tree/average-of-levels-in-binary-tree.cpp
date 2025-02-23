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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>level;
        vector<double>averages;
        level.push(root);
        while(!level.empty()){
            int size=level.size();
            long sum=0;
            for(int i=0;i<size;i++){
              TreeNode* newNode=level.front();
              level.pop();
              sum+=newNode->val;
              if(newNode->left){
                level.push(newNode->left);
              }if(newNode->right){
                level.push(newNode->right);
              }
            }
            averages.push_back(sum/(double)size);
        }
        return averages;
    }
};