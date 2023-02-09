class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int res[n];
        res[0]=nums[0];
        int max_n=nums[0];
        for(int i=1;i<n;++i){
            res[i]=max(nums[i],nums[i]+res[i-1]);
            max_n=max(max_n,res[i]);
        }
        return max_n;
    }
};