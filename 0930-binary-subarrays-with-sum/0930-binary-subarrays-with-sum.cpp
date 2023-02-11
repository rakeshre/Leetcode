class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> mp;
        
        int ct=0;
        int p_sum=0;
        for(int i=0;i<n;++i){
            p_sum+=nums[i];
            if(p_sum==goal){
                ct+=1;
            }
            if(mp.find(p_sum-goal)!=mp.end()){
                //you want k sum that ends at i.
                ct+=mp[p_sum-goal];
            }
            mp[p_sum]++;
            //here you are not entering nums[i] to map, you are doing p_sum so that p_sum-goal will return the correct number of instances 
            
        }
        return ct;
    }
};