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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum;
        levelorder_traversal(root, levelSum);
        if(k>levelSum.size()) return -1;
        sort(levelSum.begin(), levelSum.end(), greater<long long>());
        return levelSum[k-1];
    }
public:
    void levelorder_traversal(TreeNode* root, vector<long long>& levelSum) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            while(n--){
                TreeNode* node = q.front();
                q.pop();
                sum += (long long)node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            levelSum.push_back(sum);
        }
    }
};