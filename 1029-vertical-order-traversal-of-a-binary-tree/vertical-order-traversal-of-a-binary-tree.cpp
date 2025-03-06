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
        
    // void traversal(TreeNode* root,int level,map<int,vector<int>>&mp){
    //     queue<pair<TreeNode*,int>>q;
    //     q.push({root,level});
    //     while(!q.empty()){
    //         TreeNode* node=q.front().first;
    //         int level=q.front().second;
    //         mp[level].push_back(node->val);
    //         q.pop();
    //         if(node->left) q.push({node->left,level-1});
    //         if(node->right) q.push({node->right,level+1});
    //     }
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //  vector<vector<int>> traverse;
        //  map<int,vector<int>>mp;
        //  traversal(root,0,mp);
        //  for(auto it:mp){
        //     vector<int> temp=it.second;
        //     // sort(temp.begin(),temp.end());
        //     traverse.push_back(temp);
        //  }
        //  return traverse;
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;//stores nodes vertical and level
        q.push({root,{0,0}});
        while(!q.empty()){
            auto[node,value]=q.front();
            int vertical=value.first;
            int level=value.second;
            q.pop();
            nodes[vertical][level].insert(node->val);
            if(node->left) q.push({node->left,{vertical-1,level+1}});
            if(node->right) q.push({node->right,{vertical+1,level+1}});
        }
        vector<vector<int>>result;
        for(auto [vertical,levels]:nodes){
            vector<int> temp;
            for(auto[level,values]:levels){
                temp.insert(temp.end(),values.begin(),values.end());
            }
            result.push_back(temp);
        }
        return result;
    }
};