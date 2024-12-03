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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in, k);
        return in[k-1];
    }
    void inorder(TreeNode* node, vector<int> &arr, int k){
        if(node == NULL) return;
        if(node->left) inorder(node->left, arr, k);
        arr.push_back(node->val);
        if(arr.size()>k) return;
        if(node->right) inorder(node->right, arr, k);
    }
};