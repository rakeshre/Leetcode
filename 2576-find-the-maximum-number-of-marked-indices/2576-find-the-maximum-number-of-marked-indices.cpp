class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n/2;
        int res=0;
        while(i<n/2 && j<n){
            if(nums[i]*2<=nums[j]){
                res+=2;
                cout<<i<<" "<<j<<endl;
                i++;
                j++;
                
            }else{
                j++;
            }
        }
        return res;
    }
};