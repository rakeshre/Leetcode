class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> p_sum(n, 0);
        int sh_n=shifts.size();
        for(int i=0;i<sh_n;++i){
            int st=shifts[i][0];
            int ed=shifts[i][1];
            int s=(shifts[i][2]==0)?-1:1;
            p_sum[st]+=s;
            if(ed<n-1){
                p_sum[ed+1]-=s;
            }
        }
        for(int i=1;i<n;++i){
            p_sum[i]+=p_sum[i-1];
        }
        for(int i=0;i<n;++i){
            char old_char=s[i];
            int sh=p_sum[i]%26;
            char new_char;
            if(sh<0){
                new_char='a'+(old_char-'a'+26+sh)%26;
            }else{
                new_char='a'+(old_char-'a'+sh)%26;
            }
            s[i]=new_char;
        }
        return s;
    }
};