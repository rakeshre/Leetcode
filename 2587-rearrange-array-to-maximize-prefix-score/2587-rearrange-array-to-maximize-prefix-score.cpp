class Solution {
public:
    int maxScore(vector<int>& nums) {
        long sum=0;
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        int ct=0;
        for(int i=0;i<n;++i){
            sum += nums[i];
            if(sum>0){
                ct+=1;
            }
        }
        return ct;
    }
};