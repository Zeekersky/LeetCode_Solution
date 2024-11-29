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
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        findPathSum(root, sum);
        return sum;
    }
    int findPathSum(TreeNode* root, int &sum){
        if(root==NULL) return 0;
        int lh = findPathSum(root->left, sum);
        int rh = findPathSum(root->right, sum);

        if(lh>=0 && rh<0) sum = max(sum, lh+root->val);
        else if(lh<0 && rh>=0) sum = max(sum, rh+root->val);
        else if(lh<0 && rh<0) sum = max(sum, root->val);
        else sum = max(sum, lh+root->val+rh);
        
        return max(max(lh+root->val, rh+root->val), root->val);
    }
};