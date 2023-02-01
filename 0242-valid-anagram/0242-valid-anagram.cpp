class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ump;
        unordered_set<char> chs;
        for(auto ch:s){
            ump[ch]++;
            chs.insert(ch);
        }
        for(auto ch:t){
            ump[ch]--;
            chs.insert(ch);
        }
        for(auto ch:chs){
            if(ump[ch]!=0){
                return false;
            }
        }
        return true;
    }
};