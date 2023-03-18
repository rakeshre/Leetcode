class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<long> pSum;
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        int ct=0;
        if(nums[0]>0){
            ct+=1;
        }
        pSum.push_back(nums[0]);
        for(int i=1;i<n;++i){
            long sum = nums[i]+pSum[i-1];
            pSum.push_back(sum);
            if(sum>0){
                ct+=1;
            }
        }
        return ct;
    }
};