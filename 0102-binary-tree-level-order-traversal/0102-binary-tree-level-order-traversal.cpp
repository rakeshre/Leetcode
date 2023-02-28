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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> level;
            while(sz-->0){ //using size instead of adding nullptr at the end
                TreeNode* curr=q.front();
                level.push_back(curr->val);
                q.pop();
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
            res.push_back(level); // at this point previous size(sz) becomes zero, but q may not be null.
        }
        return res;
    }
};