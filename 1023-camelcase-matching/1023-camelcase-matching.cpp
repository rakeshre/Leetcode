class Solution {
public:
    bool isPref(string query, string pattern){
        int j=0;
        for(auto c:query){
            if(isupper(c) && c!=pattern[j]){
                return false;
            }
            if(c==pattern[j]){
                j++;
            }
        }
        if(j==pattern.size()){
            return true;
        }
        return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(string &query:queries){
            res.push_back(isPref(query, pattern));
        }
        return res;
    }
};