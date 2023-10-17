class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        res.push_back("");
        vector<string> dic{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(auto ch:digits){
            int id=ch-'0';
            string g=dic[id];
            vector<string> tmp;
            for(auto str:res){
                for(auto ch:g){
                    tmp.push_back(str+ch);
                }
                
            }
            res.swap(tmp);
        }
        return res;
    }
};