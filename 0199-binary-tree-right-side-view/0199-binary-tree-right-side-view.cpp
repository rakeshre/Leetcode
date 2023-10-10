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
    void dfs(TreeNode* root, vector<int> &res, int level){
        if(root==nullptr){
            return;
        }
        if(res.size()<level){
            res.push_back(root->val);
        }
        dfs(root->right, res, level+1);
        dfs(root->left, res, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int level=1;
        dfs(root, res, level);
        return res;
    }
};