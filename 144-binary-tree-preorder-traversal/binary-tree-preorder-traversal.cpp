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
        helper_iterative(root, preorder_seq);
        return preorder_seq;
    }
    void helper_recursive(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL) return;
        arr.push_back(root->val);
        helper_recursive(root->left, arr);
        helper_recursive(root->right, arr);
    }
    void helper_iterative(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            arr.push_back(node->val);
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
    }
};