class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n,start);
        for(int i=0;i<n;++i){
           nums[i]+=2*i; 
        }
        int res=0;
        for(auto &x:nums){
            res=res^x;
        }
        return res;
    }
};