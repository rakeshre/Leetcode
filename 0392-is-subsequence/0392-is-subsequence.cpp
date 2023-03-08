class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int s_n=s.size();
        int t_n=t.size();
        while(i<s_n &&j<t_n){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i>=s_n){
            return true;
        }
        return false;
    }
};