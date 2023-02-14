class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string str=to_string(x);
        int n=str.size();
        int s=0,e=n-1;
        while(s<=e){
            if(str[s]!=str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};