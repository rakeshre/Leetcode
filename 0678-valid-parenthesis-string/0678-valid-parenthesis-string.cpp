class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int leftP=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(' || s[i]=='*'){
                leftP++;
            }else{
                leftP--;
            }
            if(leftP<0){
                return false;
            }
        }
        int rightP=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==')'||s[i]=='*'){
                rightP++;
            }else{
                rightP--;
            }
            if(rightP<0){
                return false;
            }
        }
        
        return true;
    }
};