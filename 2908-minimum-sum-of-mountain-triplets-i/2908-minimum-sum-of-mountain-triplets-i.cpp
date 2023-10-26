class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int minSum=INT_MAX;
        for(int i=1;i<n-1;++i){
            int l=INT_MAX;
            int r=INT_MAX;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    l=min(l,nums[j]);
                }
            }
            for(int j=i+1;j<n;++j){
                if(nums[j]<nums[i]){
                    r=min(r,nums[j]);
                }
            }
            if(l!=INT_MAX && r!=INT_MAX){
                int sum=nums[i]+l+r;
                minSum=min(minSum,sum);
            }
        }
        if(minSum==INT_MAX){
            return -1;
        }
        return minSum;
    }
};