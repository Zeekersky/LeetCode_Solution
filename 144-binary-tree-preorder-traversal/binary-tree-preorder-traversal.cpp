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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder_seq;
        helper(root, preorder_seq);
        return preorder_seq;
    }
    void helper(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL) return;
        arr.push_back(root->val);
        helper(root->left, arr);
        helper(root->right, arr);
    }
};