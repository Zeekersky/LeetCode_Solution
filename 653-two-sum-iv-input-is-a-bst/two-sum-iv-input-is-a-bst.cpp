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
class BSTIterator {
public:
    // Reverse = true -> before
    // Reverse = false -> next
    stack<TreeNode*> st;
    bool reverse = false;
    BSTIterator(TreeNode* root, bool isReverse) {
        TreeNode* node = root;
        reverse = isReverse;
        while(node){
            st.push(node);
            if(!reverse) node = node->left;
            else node = node->right;
        }
    }
    
    int next() {
        TreeNode* node = st.top(); st.pop();
        int ans = node->val;
        if(!reverse){
            if (node->right) {
                node = node->right;
                while (node) {
                    st.push(node);
                    node = node->left;
                }
            }
        }
        else{
            if (node->left) {
                node = node->left;
                while (node) {
                    st.push(node);
                    node = node->right;
                }
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator left(root, false);
        BSTIterator right(root, true);
        int l = left.next();
        int r = right.next();
        while(l<r){
            if(l+r == k) return true;
            if(l+r < k) l = left.next();
            else r = right.next();
        }
        return false;
    }
};