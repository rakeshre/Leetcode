class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1;
        int i=0;
        while(i<n && i<=e){
            if(nums[i]==2){
                swap(nums[e],nums[i]);
                e--;
            }else if(nums[i]==0){
                swap(nums[s],nums[i]);
                s++;
                i++;
            }else{
                i++;
            }
            
        }
    }
};