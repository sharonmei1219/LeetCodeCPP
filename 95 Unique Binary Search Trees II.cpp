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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> empty = {};
        if(n == 0) return {};
        vector<vector<TreeNode*>> row(n+2, empty);
        vector<vector<vector<TreeNode*>>> matrix(n+1, row);
        vector<TreeNode*> result;
        
        for(int i = 0; i < n+2; i++){
            matrix[0][i] = {nullptr};
        }
        
        for(int len = 1; len <= n; len++){
            for(int i = 1; i <= n-len+1; i++){
                for(int k = i; k <= i+len-1; k++){
                    const int leftLen = k - i, l = i;
                    const int rightLen = i+len-1-k, r = k+1;
                    vector<TreeNode*> leftTreeSet = matrix[leftLen][l];
                    vector<TreeNode*> rightTreeSet = matrix[rightLen][r];
                    mergeto(matrix[len][i], k, leftTreeSet, rightTreeSet);
                }
            }
        }
        
        return matrix[n][1];
    }
    
    void mergeto(vector<TreeNode*> & toSet, int k, vector<TreeNode*> &l, vector<TreeNode*> &r){
        for(auto li = l.begin(); li < l.end(); li++){
            for(auto ri = r.begin(); ri < r.end(); ri++){
                TreeNode * tree = new TreeNode(k, *li, *ri);
                toSet.push_back(tree);
            }
        }
    }
};