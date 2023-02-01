class Solution {
public:
    bool isPalindrome(string s) {
        string trc="";
        for(int i=0;i<s.size();++i){
            if(isdigit(s[i])){
                trc+=s[i];
            }
            if(isalpha(s[i])){
                trc+=tolower(s[i]);
            }
        }
        string t_c=trc;
        reverse(trc.begin(),trc.end());
        return t_c==trc;
    }
};