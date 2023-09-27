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
    bool isValid(TreeNode* root, long low, long high){
        if(root==nullptr){
            return true;
        }
        if(root->val>low && root->val<high){
            return isValid(root->left, low,root->val) && isValid(root->right, root->val,high);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN,LONG_MAX); //instead of using int_max and min, we can alternatively use nuulptrs and start from root(root,null,null). As we traverse down, we can change left or right appropriately. 
        
    }
};