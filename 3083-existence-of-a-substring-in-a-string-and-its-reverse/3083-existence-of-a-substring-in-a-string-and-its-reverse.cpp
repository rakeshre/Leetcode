class Solution {
public:
    
    bool isSubstringPresent(string s) {
        int n=s.size();
        unordered_set<string> set_str;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                set_str.insert(s.substr(i,j-i+1));
            }
        }
        reverse(s.begin(),s.end());
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(set_str.find(s.substr(i,j-i+1))!=set_str.end()){
                    return true;
                }
            }
        }
        return false;
    }
};