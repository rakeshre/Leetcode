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
    int pathsub(TreeNode* root, int &mx){
        if(root==nullptr){
            return 0;
        }
        int l=pathsub(root->left,mx);
        int r=pathsub(root->right,mx);
        //cout<<l<<" "<<r<<" ";
        l=max(l,0);
        r=max(r,0);
        //mx=max(mx,root->val);
        mx=max(mx,l+r+root->val);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int mx=INT_MIN;
        pathsub(root,mx);
        return mx;
    }
};