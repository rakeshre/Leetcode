class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string a=strs[0];
        int l=a.size();
        string b=strs[n-1];
        string ans="";
        for(int i=0;i<l;++i){
            if(a[i]==b[i]){
                //cout<<i;
                ans+=a[i];
            }else{
                break;
            }
        }
        return ans;
    }
};