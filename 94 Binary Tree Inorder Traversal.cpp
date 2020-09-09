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
        if(root == nullptr) return {};
        TreeNode * node = root;
        vector<int> result;
        vector<TreeNode*> stack = {};
        while(node != nullptr || stack.size() > 0){
            while(node != nullptr){
                stack.push_back(node);
                node = node->left;
            }
            node = stack.back();
            stack.pop_back();
            result.push_back(node->val);
            node = node->right;
        }
        return result;
    }
};