class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0, e=nums.size()-1;
        while(st<=e){
            int mid=st+(e-st)/2;
        if(nums[mid]<target){
            st=mid+1;
        }else if(nums[mid]>target){
            e=mid-1;
        }else{
            return mid;
        }
        }
        return -1;
    }
};