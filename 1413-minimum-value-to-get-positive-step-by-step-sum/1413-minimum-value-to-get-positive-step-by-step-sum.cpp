class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pSum(n,0);
        pSum[0]=nums[0];
        int min_num=nums[0];
        for(int i=1;i<n;++i){
            pSum[i]=pSum[i-1]+nums[i];
            min_num=min(pSum[i], min_num);
        }
        if(min_num>=1){
            return 1;
        }
        int ans=1-min_num;
        return ans;     
        
    }
};