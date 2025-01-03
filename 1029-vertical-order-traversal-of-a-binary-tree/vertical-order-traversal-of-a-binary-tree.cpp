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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            mp[vertical][level].insert(node->val);
            if(node->left) q.push({node->left, {vertical-1, level+1}});
            if(node->right) q.push({node->right, {vertical+1, level+1}});
        }
        vector<vector<int>> res;
        for(auto it:mp){
            vector<int> col;
            for(auto it_col: it.second)
                col.insert(col.end(), it_col.second.begin(), it_col.second.end()); // Entire multiset will be inserted
            res.push_back(col);
        }
        return res;
    }
};