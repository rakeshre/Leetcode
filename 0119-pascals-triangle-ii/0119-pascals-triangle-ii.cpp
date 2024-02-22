class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        if(rowIndex==1){
            return {1,1};
        }
        vector<int> prev={1,1};
        for(int i=2;i<=rowIndex;++i){
            vector<int> res{1};
            for(int j=1;j<i;++j){
                res.push_back(prev[j]+prev[j-1]);
            }
            res.push_back(1);
            prev=res;
        }
        return prev;
        
    }
};