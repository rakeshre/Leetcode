class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> unique_triplets;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;++i){
            int j=i+1;
            int k=n-1;
            while(j<k){
               if(nums[i]+nums[j]+nums[k]==0){
                   unique_triplets.insert({nums[i],nums[j],nums[k]});
                   j++;
                   k--;
               }else if(nums[i]+nums[j]+nums[k]<0){
                   j++;
               }else{
                   k--;
               }
            }
        }
        for(auto entry:unique_triplets){
            res.push_back(entry);
        }
        return res;
    }
};