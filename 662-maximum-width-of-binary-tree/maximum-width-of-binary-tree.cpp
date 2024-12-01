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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long width = 0;
        while(!q.empty())
        {
            int n = q.size();
            long long nmin = q.front().second;
            long long max_ind, min_ind;
            for(int i = 0; i<n; i++)
            {
                TreeNode* node = q.front().first;
                long long index = q.front().second-nmin;
                q.pop();
                if(i==0) min_ind = index;
                if(i==n-1) max_ind = index;
                if(node->left) q.push({node->left, 2*(index)+1});
                if(node->right) q.push({node->right, 2*(index)+2});
            }
            width = max(width, max_ind-min_ind+1);
        }
        return width;
    }
};