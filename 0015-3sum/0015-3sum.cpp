class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> u_s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    u_s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        vector<vector<int>> res;
        for(auto x:u_s){
            res.push_back(x);
        }
        return res;
    }
};