class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        int odd_c=0;
        unordered_map<char, int> s_m;
        bool odd=false;
        for(auto ch:s){
            s_m[ch]+=1;
        }
        for(auto pair: s_m){
            int val=pair.second;
            if(val%2==0){
                count+=val;
            }else{
                count+=(val-1);
                odd_c+=1;
            }
        }
        if(odd_c>=1){
            count+=1;
        }
        
        return count;
    }
};