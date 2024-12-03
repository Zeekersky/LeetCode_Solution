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
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        int left = 0, right = arr.size()-1;
        while(left<right){
            int tot = arr[left] + arr[right];
            if(tot == k) return true;
            if(tot < k) left++;
            else right--;
        }
        return false;
    }
    void inorder(TreeNode* root, vector<int> &arr){
        if(!root) return;
        if(root->left) inorder(root->left, arr);
        arr.push_back(root->val);
        if(root->right) inorder(root->right, arr);
    }
};