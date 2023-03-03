class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.size();
        long long val=0;
        vector<int> res;
        for(int i=0;i<n;++i){
            val= (val*10 + word[i]-'0')%m;
            if(val%m==0){
                res.push_back(1);
            }else{
                res.push_back(0);
            }
        }
        return res;
    }
};