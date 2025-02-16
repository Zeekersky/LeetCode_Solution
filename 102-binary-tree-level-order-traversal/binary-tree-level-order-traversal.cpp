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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, ans);
        return ans;
    }
    void helper(TreeNode *root, vector<vector<int>> &ans)
    {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level_track;
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level_track.push_back(node->val);
            }
            ans.push_back(level_track);
        }
    }
};