class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visit;
        int i=0,j=0, n=s.size(),maxnum=0;
        while(j<n){
            if(visit.find(s[j])==visit.end()){
                visit.insert(s[j]);
                maxnum=max(maxnum,j-i+1);
                j++;
            }else{
                visit.erase(s[i]);
                i++;
            }
            
        }
        return maxnum;
    }
};