class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            res.push_back(nums[i]+sum);
            sum+=nums[i];
        }
        return res;
    }
};