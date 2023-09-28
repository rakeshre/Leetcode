class Solution {
public:
    int binarySearch(vector<int>& nums, int st, int end, int target){
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        //find pivot
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]<=nums[n-1]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        //do search
        int idx=binarySearch(nums, 0, s-1, target); //because s is pivot.
        if(idx!=-1){
            return idx;
        }
        return binarySearch(nums, s, n-1, target);
    }
    
};