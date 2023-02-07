class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct=0;
        int ele;
        for(int i=0;i<nums.size();++i){
            if(ct==0){
                ele=nums[i];
            }
            if(nums[i]==ele){
                ct+=1;
            }else{
                ct-=1;
            }  
        }
        return ele;
    }
};