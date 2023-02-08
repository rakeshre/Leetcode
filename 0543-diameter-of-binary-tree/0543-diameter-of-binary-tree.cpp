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
    int helper(TreeNode* root, int &ans){
        if(root==nullptr){
            return 0;
        }
        int l=0,r=0;
        if(root->left){
            l+=(helper(root->left, ans)+1);
        }
        if(root->right){
            r+=(helper(root->right, ans)+1);
        }
        ans=max(ans,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};