class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ct=0,st=0;
        int res=0;
        for(int end=0;end<n;++end){
            if(nums[end]==0){
                ct++;
            }
            while(ct>k){
                if(nums[st]==0){
                    ct--;
                }
                st++;
            }
            res=max(res,end-st+1);
        }
       return res; 
    }
};