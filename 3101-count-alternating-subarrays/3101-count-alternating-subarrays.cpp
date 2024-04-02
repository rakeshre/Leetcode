class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long sum=1;
        int prev=0;
        for(int i=1;i<n;++i){
            if(nums[i]!=nums[i-1]){
                sum+=(i-prev)+1;
            }else{
                sum+=1;
                prev=i;
            }
        }
        return sum;
    }
};