class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s_m(26,0);
        vector<int> p_m(26,0);
        vector<int> res;
        int s_l=s.size();
        int p_l=p.size();
        if(s_l<p_l){
            return res;
        }
        int left=0;
        int right=0;
        for(int i=0;i<p_l;++i){
            p_m[p[i]-'a']++;
            s_m[s[i]-'a']++;
            right++;
        }
        right--;
        while(right<s_l){
            if(s_m==p_m){
                res.push_back(left);
            }
            if(right!=s_l-1){
                s_m[s[right+1]-'a']++;
                s_m[s[left]-'a']--;
            }
            right++;
            left++;
        }
        return res; 
    }
};