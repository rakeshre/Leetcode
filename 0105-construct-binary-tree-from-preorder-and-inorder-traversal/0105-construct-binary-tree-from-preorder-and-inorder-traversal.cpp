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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int &rootInd, int left, int right){
        if(left>right){
            return nullptr;
        }
        int pivot=left;
        while(inorder[pivot]!=preorder[rootInd]){
            pivot++;
        }
        rootInd=rootInd+1;
        TreeNode *mid=new TreeNode(inorder[pivot]);
        //imp to note that rootInd is passed as reference, so it is updated accordingly.
        mid->left=dfs(preorder, inorder, rootInd, left, pivot-1);
        mid->right=dfs(preorder, inorder, rootInd, pivot+1, right);
        return mid;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootInd=0;
        int n=preorder.size();
        TreeNode* root=dfs(preorder, inorder, rootInd, 0, n-1);
        return root;
        
    }
};