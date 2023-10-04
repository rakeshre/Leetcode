class Solution {
public:
    void dfs(vector<int>& nums, int i, int k, unordered_map<int,int> &mp, int &ans){
        if(i==nums.size()){
            ans++;
        }else{
            if(!mp[nums[i]-k] && !mp[nums[i]+k]){
            mp[nums[i]]++;
            dfs(nums, i+1, k, mp, ans);
            mp[nums[i]]--;
        }
            dfs(nums, i+1, k, mp, ans);
        }
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
        int ans=0;
       dfs(nums, 0,k,mp,ans);
        return ans-1;//-1 for empty set
    }
};