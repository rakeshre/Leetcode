class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n=sentence.size();
        if(n<26){
            return false;
        }
        unordered_map<char, int> mp;
        for(auto ch:sentence){
            mp[ch]++;
        }
        for(int i=0;i<26;++i){
            char ch='a'+i;
            if(mp[ch]<1){
                return false;
            }
        }
        return true;
    }
};