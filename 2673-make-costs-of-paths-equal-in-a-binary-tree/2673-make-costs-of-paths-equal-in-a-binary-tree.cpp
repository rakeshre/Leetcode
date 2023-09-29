// class Node{
   
// }; --- dumb!!
class Solution {
public:
    // int getSum(Node *root, int &r){
    //     if(root->left==nullptr && root->right==nullptr){
    //         return root->val;
    //     }
    //     int ls=getSum(root->left,r);
    //     int rs=getSum(root->right, r);
    //     r+=abs(rs-ls);
    //     return root->val;
    // }
    int minIncrements(int n, vector<int>& cost) {
        //you need to traverse bottom-up 
        int res=0;
        for(int i=n/2-1;i>=0;--i){
            int l=cost[2*i+1];
            int r=cost[2*i+2];
            res+=abs(l-r);
            cost[i]+=max(l,r);
        }
        return res;
    }
};