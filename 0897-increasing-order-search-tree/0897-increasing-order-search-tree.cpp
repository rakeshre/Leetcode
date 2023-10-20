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
// class Solution {
// public:
//     TreeNode* increasingBST(TreeNode* root) {
//         if(root==nullptr){
//             return nullptr;
//         }
//         if(root->left==nullptr){
//             return root;
//         }
//         TreeNode* l=increasingBST(root->left);
//         if(l!=nullptr){
//             l->right=root;
//         }
//         TreeNode* r=increasingBST(root->right);
//         if(r==nullptr){
            
//         }else{
//             root->right=r;
//         }
        
//         cout<<root->val<<" ";
//         return l;
        
//     }
// };

class Solution {
public:
void inorder(TreeNode* root,vector<int>& ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        TreeNode* dummy=new TreeNode(0);
        TreeNode* current=dummy;
        for(int i=0;i<ans.size();i++)
        {
            current->right=new TreeNode(ans[i]);
            current=current->right;
        }
        return dummy->right;
        
    }
};