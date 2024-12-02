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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[0]);
        int index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());
        
        node->left = buildTree(leftPreorder, leftInorder);
        node->right = buildTree(rightPreorder, rightInorder);
    
        return node;
    }
};