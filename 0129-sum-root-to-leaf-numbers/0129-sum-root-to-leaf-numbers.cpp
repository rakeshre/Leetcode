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
    int cum_sum=0;
    int sum_to_leaf(TreeNode* root, int preSum){
        if(root!=nullptr){
            int sum_level=preSum*10 + root->val;
            if(root->left==nullptr && root->right==nullptr){
                cum_sum+=sum_level;
            }
            return sum_to_leaf(root->left, sum_level) + sum_to_leaf(root->right, sum_level);
        }
        return 0;
    }
    int sumNumbers(TreeNode* root) {
         sum_to_leaf(root, 0);
        return cum_sum;
    }
};