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
    bool isValidBST(TreeNode* root) {
        // if(root==NULL) return true;
        return isValidMargin(root, LONG_MIN, LONG_MAX);
    }
    bool isValidMargin(TreeNode* root, long long leftMargin, long long rightMargin)
    {
        if(root == NULL) return true;
        if((root->val <= leftMargin) || (root->val >= rightMargin))
            return false;
        return isValidMargin(root->left, leftMargin, root->val) && isValidMargin(root->right, root->val, rightMargin);
    }
};