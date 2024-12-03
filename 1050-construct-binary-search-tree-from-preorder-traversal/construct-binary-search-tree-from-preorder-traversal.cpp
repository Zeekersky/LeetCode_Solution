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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            findPlace(root, preorder[i]);
        }
        return root;
    }
    void findPlace(TreeNode* root, int &val){
        if(root->val > val && root->left) findPlace(root->left, val);
        else if(root->val < val && root->right) findPlace(root->right, val);
        else if(root->val > val){
            TreeNode* node = new TreeNode(val);
            root->left = node;
        }
        else if(root->val < val){
            TreeNode* node = new TreeNode(val);
            root->right = node;
        }
        return;
    }
};