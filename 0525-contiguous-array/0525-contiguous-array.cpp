class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*
        int n=nums.size();
        vector<int> p_sum=nums;
        int ans=0;
        for(int i=1;i<n;++i){
            p_sum[i]+=p_sum[i-1];
             int n_one=p_sum[i];
            int n_zero=i+1-n_one;
            if(n_one==n_zero){
                ans=n_one*2;
            }
            if(abs(n_one-n_zero)==1){
                ans=min(n_one,n_zero)*2;
            }
            return ans;
        }
        */
        //the problem above is you are considering an entire slot from start i.e [0..i].instead, consider subtracting the point with sum from the last time you encountered it. 
        unordered_map<int,int> mp;
        int sum=0;
        int slot_len=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();++i){
            sum+=(nums[i]==0)?-1:1;
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }else{
                slot_len=max(slot_len,i-mp[sum]);
                //observe that we are not updating the sum value in map. we are storing the index where it first appeared.
            }
        }
        return slot_len;
    }
};