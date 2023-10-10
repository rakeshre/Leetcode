class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<int> &sub_set, vector<vector<int>> &res){
        int n=nums.size();
        if(i==n){
            res.push_back(sub_set);
            return;
        }
        sub_set.push_back(nums[i]);
        dfs(nums, i+1, sub_set, res);
        sub_set.pop_back();
        dfs(nums, i+1, sub_set, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        vector<int> emp;
        //result.push_back(emp);
        dfs(nums, 0, emp, res);
        return res;
    }
};