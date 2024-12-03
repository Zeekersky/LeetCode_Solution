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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        TreeNode* target = searchNode(root, key);
        if (!target) return root;

        unordered_map<TreeNode*, TreeNode*> parent;
        parentTrack(root, parent);

        if (!target->left && !target->right) {
            if (parent.find(target) != parent.end()) {
                TreeNode* par = parent[target];
                if (par->left == target) par->left = NULL;
                else par->right = NULL;
            } else {
                root = NULL;
            }
        } 
        else if (target->left) {
            TreeNode* predecessor = target->left;
            while (predecessor->right)
                predecessor = predecessor->right;

            target->val = predecessor->val;

            TreeNode* predParent = parent[predecessor];
            if (predParent->left == predecessor) 
                predParent->left = predecessor->left;
            else 
                predParent->right = predecessor->left;
        } 
        else {
            TreeNode* successor = target->right;
            while (successor->left)
                successor = successor->left;

            target->val = successor->val;

            TreeNode* succParent = parent[successor];
            if (succParent->left == successor) 
                succParent->left = successor->right;
            else 
                succParent->right = successor->right;
        }

        return root;
    }

    TreeNode* searchNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key) return root;
        if (root->val > key) return searchNode(root->left, key);
        return searchNode(root->right, key);
    }

    void parentTrack(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
};
