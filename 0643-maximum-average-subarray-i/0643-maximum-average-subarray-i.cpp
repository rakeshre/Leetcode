class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0,maxsum=0;
        double res=0.0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
        }
        maxsum=sum;
        for(int i=k;i<n;++i){
            sum-=nums[i-k];
            sum+=nums[i];
            maxsum=max(sum,maxsum);
        }
        res=maxsum/k;
        cout<<maxsum<<" ";
        return res;
    }
};