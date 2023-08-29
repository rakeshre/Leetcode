class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int prod=n*(n+1);
        int sum=prod/2;
        int act_sum=0;
        for(int i=0;i<n;++i){
            act_sum+=nums[i];
        }
        return sum-act_sum;
    }
};