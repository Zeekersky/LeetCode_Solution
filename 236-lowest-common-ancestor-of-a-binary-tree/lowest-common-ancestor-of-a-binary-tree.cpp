/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        if(root == NULL) return root;
        getPath(root, pathP, p);
        getPath(root, pathQ, q);
        int n = pathP.size()<pathQ.size()? pathP.size():pathQ.size();
        TreeNode* ans;
        if(pathP[n-1] == pathQ[n-1])
            ans = pathP[n-1];
        else {
            for(int i = 0; i<n; i++)
            {
                if(pathP[i]!=pathQ[i]){  
                    ans = pathP[i-1];
                    break;
                }
            }
        }

        return ans;
    }
    bool getPath(TreeNode* root, vector<TreeNode*> &arr, TreeNode* node)
    {
        if(!root) return false;
        arr.push_back(root);
        if(root == node)
            return true;
        if(getPath(root->left, arr, node) || getPath(root->right, arr, node))
            return true;
        arr.pop_back();
        return false;
    }
};