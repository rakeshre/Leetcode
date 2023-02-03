class NumArray {
public:
    vector<int> &sum_arr;
    NumArray(vector<int>& nums): sum_arr(nums){
        for(int i=1;i<nums.size();++i){
            sum_arr[i]+=sum_arr[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return sum_arr[right];
        }
        return sum_arr[right]-sum_arr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */