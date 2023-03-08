/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void t_down(TreeNode* root, int n, vector<int> & res){
        if(root==nullptr){
            return;
        }
        if(n==0){
            res.push_back(root->val);
        }else{
            t_down(root->left,n-1,res);
            t_down(root->right,n-1,res);
        }
    }
    int subfunc(TreeNode* root, TreeNode* target, int k, vector<int> &res){
        if(root==nullptr){
            return -1;
        }
        if(root==target){
            t_down(root,k,res);
            return k-1;
        }
        int l=subfunc(root->left,target,k, res);
        int r=subfunc(root->right,target,k, res);
        if(l==0 ||r==0){
            res.push_back(root->val);
        }
        if(l>0){
            t_down(root->right,l-1, res);
            return l-1;
        }
        if(r>0){
            t_down(root->left,r-1, res);
            return r-1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        subfunc(root, target, k, res);
        return res;
        
        
    }
};