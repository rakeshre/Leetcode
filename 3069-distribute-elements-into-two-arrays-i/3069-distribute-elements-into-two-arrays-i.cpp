class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i=2;i<nums.size();++i){
            if(v1.back()>v2.back()){
                v1.push_back(nums[i]);
            }else{
                v2.push_back(nums[i]);
            }
        }
        vector<int> res;
        for(auto x:v1){
            res.push_back(x);
        }
        for(auto y:v2){
            res.push_back(y);
        }
        return res;
    }
};