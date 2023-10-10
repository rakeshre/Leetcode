class Solution {
public:
    
    // bool canPartition(vector<int>& nums) {
    //    int sum=0;
    //    int n=nums.size();
    //    for(int i=0;i<n;++i){
    //        sum+=nums[i];
    //    }
    //    if(sum%2==1){
    //         return false;
    //    }
    //    sum=sum/2;
    //     vector<bool> cache(sum+1,false);
    //     cache[0]=true;
    //    for(auto num:nums){
    //        //cache[num]=true;//if we do this, we can reuse a number to get req sum.
    //        for(int i=sum;i>=num;--i){ //if we come from num to sum, in the first iteration only, we make cache[num] as true. which result in reuse.
    //            cache[i]=cache[i]||cache[i-num];//i->pick it, i-num-> don't pick it.
    //        }
    //    }
    //     return cache[sum];
    // }
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
       vector<vector<bool>> cache(n+1, vector<bool>(sum+1, false));
         cache[0][0]=true;
       for(int i=1;i<=n;++i){
           int curr=nums[i-1];
           for(int j=0;j<=sum;++j){
               if(j<curr){
                   cache[i][j]=cache[i-1][j];
               }else{
                   cache[i][j]=cache[i-1][j] || cache[i-1][j-curr];
               }
           }
       }
       return cache[n][sum];
    }
};