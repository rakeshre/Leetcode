class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n_s;
        for(int x:nums){
            if(n_s.find(x)!=n_s.end()){
                return true;
            }
            n_s.insert(x);
        }
        return false;
    }
};