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
        vector<vector<int>> result;
        if(root == NULL) return result;
        bool flag_leftright = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level(n);
            for(int i=0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                int ind = flag_leftright ? i : n - i - 1;
                level[ind] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag_leftright = !flag_leftright;
            result.push_back(level);
        }
        return result;
    }
};