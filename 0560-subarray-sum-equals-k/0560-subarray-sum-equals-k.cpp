class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> num_map;
        //unordered_set<int> num_set;
        int ct=0;
        num_map[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(num_map.find(sum-k) != num_map.end()){
                ct+=num_map[sum-k];
            }
            num_map[sum]+=1;
        }
        return ct;
    }
};