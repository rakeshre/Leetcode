class Solution {
public:
    bool isPossible(vector<int>& nums, vector<int>& changeIndicesZeroIdx, int s){
        unordered_map<int,int> last;
        int n=nums.size();
        int power=0,comp=0;
        for(int i=0;i<=s;++i){
            last[changeIndicesZeroIdx[i]]=i;
        }
        for(int i=0;i<=s;++i){
            int id=changeIndicesZeroIdx[i];
            if(i==last[id]){
                if(power<nums[id]){
                    return false;
                }else{
                    power-=nums[id];
                    comp++;
                }
            }else{
                power++;
            }
        }
        return comp==n;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        vector<int> changeIndicesZeroIdx=changeIndices;
        int n=nums.size();
        int m=changeIndices.size();
        for(auto &el:changeIndicesZeroIdx){
            el--;
        }
        int l=0,h=m-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(nums,changeIndicesZeroIdx,mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans==-1?-1:ans+1;
        
    }
};