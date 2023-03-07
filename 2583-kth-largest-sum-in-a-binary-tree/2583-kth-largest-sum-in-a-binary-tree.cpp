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
    void levelSum(TreeNode* root, int level, vector<long long> &ar){
        if(root==nullptr){
            return;
        }
        ar[level]+=root->val;
        levelSum(root->left,level+1, ar);
        levelSum(root->right,level+1, ar);
        return;
    }
    int depth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        return 1+max(depth(root->left),depth(root->right));
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int d=depth(root);
        if(k>d){
            return -1;
        }
        vector<long long> ar(d,0);
        levelSum(root,0,ar);
        for(int x:ar){
            cout<<x<<" ";
        }
        priority_queue<long long> pq;
        for(int i=0;i<d; ++i){
            pq.push(ar[i]);
        }
        while(k-->1){
            pq.pop();
        }
        return pq.top();
        
    }
};