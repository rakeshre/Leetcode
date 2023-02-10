class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev{1};
        res.push_back(prev);
        if(numRows==1){
            return res;
        }
        while(prev.size()<=numRows-1){
            vector<int> curr;
            curr.push_back(1);
            for(int i=0;i<prev.size()-1;++i){
               curr.push_back(prev[i]+prev[i+1]); 
            }
            curr.push_back(1);
            res.push_back(curr);
            prev=curr;
        }
        return res;
    }
};