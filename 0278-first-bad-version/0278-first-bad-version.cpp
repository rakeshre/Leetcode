// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st=1,ed=n;
        while(st<=ed){
           int mid=st+(ed-st)/2;
           if(isBadVersion(mid)){
           if(mid==1){
                return 1;
            }
            if(!isBadVersion(mid-1)){
                return mid;
            }
               ed=mid-1;
            }else{
               st=mid+1;
           } 
        }
        return -1;
        
    }
};