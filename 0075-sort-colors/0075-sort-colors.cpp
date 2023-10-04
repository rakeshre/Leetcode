class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ct(3,0);
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                ct[0]++;
            }else if(nums[i]==1){
                ct[1]++;
            }else{
                ct[2]++;
            }
        }
        for(int i=0;i<nums.size();++i){
            if(i<ct[0]){
                nums[i]=0;
            }else if(i<ct[0]+ct[1]){
                nums[i]=1;
            }else{
                nums[i]=2;
            }
        }
    }
};