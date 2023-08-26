class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<long long> pSum(n+1);
        vector<int> ret(n,-1);
        int div = 2*k+1;
        if(2*k+1>n){
            return ret;
        }
        for(int i=0;i<n;++i){
            pSum[i+1]=pSum[i]+nums[i];
        }
        for(int i=0;i<n;++i){
            if(i>=k && i<n-k){
                long long num=pSum[i+k+1]-pSum[i-k];//changed from int to long
                ret[i]=num/div;
            }
        }
        return ret;
    }
};