class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jwl;
        for(auto ch:jewels){
            jwl.insert(ch);
        }
        int ret=0;
        for(auto ch:stones){
            if(jwl.find(ch)!=jwl.end()){
                ret++;
            }
        }
        return ret;
    }
};