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
    bool isValidBST(TreeNode* root) {
        long r = (long)INT_MAX + 1, l = (long)INT_MIN - 1;
        return isValidBSTInRange(root, l, r);
    }
    
    bool isValidBSTInRange(TreeNode * root, long l, long r){
        if(root == nullptr) return true;
        if((long)root->val >= r) return false;
        if((long)root->val <= l) return false; 
        return isValidBSTInRange(root->left, l, root->val)
            && isValidBSTInRange(root->right, root->val, r);
    }
};