class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
       int sum=0;
       int n=nums.size();
       for(int i=0;i<n;++i){
           sum+=nums[i];
       }
       if(sum%2==1){
            return false;
       }
       sum=sum/2;
        vector<bool> cache(sum+1,false);
        cache[0]=true;
       for(auto num:nums){
           //cache[num]=true;//if we do this, we can reuse a number to get req sum.
           for(int i=sum;i>=num;--i){ //if we come from num to sum, in the first iteration only, we make cache[num] as true. which result in reuse.
               cache[i]=cache[i]||cache[i-num];//i->pick it, i-num-> don't pick it.
           }
       }
        return cache[sum];
    }
};