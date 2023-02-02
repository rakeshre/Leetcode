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
    /*
    int height(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    */
    bool isBalancedHelper(TreeNode* root, int &height){
        if(root==nullptr){
            height=0;
            return true;
        }
        int left=0, right=0;
        bool leftBal=isBalancedHelper(root->left,left);
        bool rightBal=isBalancedHelper(root->right,right);
        if(abs(left-right)>1){
            return false;
        }
        if(leftBal==false ||rightBal==false){
            return false;
        }
        height=max(left,right)+1;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        /*
        if(root==nullptr){
            return true;
        }
        if(abs(height(root->left)-height(root->right))>1){
            return false;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(left==false || right==false){
            return false;
        }
        return true;
        */
        int height=0;
        return isBalancedHelper(root,height);
    }
};