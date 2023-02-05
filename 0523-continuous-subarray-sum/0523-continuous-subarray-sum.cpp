class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> num_set;
        vector<int> p_sum=nums;
        num_set[nums[0]%k]=0;
        for(int i=1;i<nums.size();++i){
            p_sum[i]+=p_sum[i-1];
            if(p_sum[i]%k==0){
                return true;
            }
            /*
            if(nums[i]!=0 && nums[i]%k==0){
                continue;
            }
            */
            int rem=p_sum[i]%k;
            if(num_set.find(rem)!=num_set.end()){
                int st=num_set[rem];
                if(i-st>1){
                    return true;
                }
            }else{
                num_set[rem]=i;
            }
        }
        return false;
    }
};