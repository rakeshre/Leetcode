class Solution {
public:
    
    int findLUSlength(string a, string b) {
        int a_l=a.size();
        int b_l=b.size();
        if(a==b){
            return -1;
        }
        return max(a_l,b_l);
    }
};