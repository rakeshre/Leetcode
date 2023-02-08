class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        int ls=0;
        for(int i=0;i<n;++i){
            if(ls==sum-nums[i]-ls){
                return i;
            }
            ls+=nums[i];    
        }
        return -1;
    }
};