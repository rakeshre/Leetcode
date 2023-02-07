class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mgz_ch;
        for(auto ch:magazine){
            mgz_ch[ch]++;
        }
        for(auto ch:ransomNote){
            if(mgz_ch[ch]>0){
                mgz_ch[ch]--;
            }else{
                return false;
            }
        }
        return true;
    }
};