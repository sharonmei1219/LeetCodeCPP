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
    void recoverTree(TreeNode* root) {
        TreeNode * l = nullptr, * r = nullptr, * org = new TreeNode(INT_MIN), * last = org;
        transverse(root, l, r, last);
        int tmp = l->val;
        l->val = r->val;
        r->val = tmp;
        return;
    }
    
    void transverse(TreeNode *root, TreeNode *&l, TreeNode *&r, TreeNode *&last){
        if(root == nullptr) return;
        transverse(root->left, l, r, last);
        
        if((root->val < last->val) && l == nullptr){ l = last; }
        if((root->val < last->val) && l != nullptr){ r = root; }
        last = root;
        transverse(root->right, l, r, last);
    }
};