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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> inorder_seq;
        helper_iterative(root, inorder_seq);
        return inorder_seq;
    }
    void helper_recursive(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL) return;
        helper_recursive(root->left, arr);
        arr.push_back(root->val);
        helper_recursive(root->right, arr);
    }
    void helper_iterative(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL) return;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty()) return;
                node = st.top();
                st.pop();
                arr.push_back(node->val);
                node = node->right;
            }
        }
    }
};