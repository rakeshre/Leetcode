class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> res;
        int sr=0,sc=0,er=m-1,ec=n-1;
        while(sr<=er && sc<=ec){
            //right
            for(int j=sc;j<=ec;++j){
                if(sr<=er){
                    res.push_back(matrix[sr][j]);
                }
            }
            sr++;
            //down
            for(int i=sr;i<=er;++i){
                if(sc<=ec){
                    res.push_back(matrix[i][ec]);
                }
            }
            ec--;
            //left
            for(int j=ec;j>=sc;--j){
                if(sr<=er){
                    res.push_back(matrix[er][j]);
                }
            }
            er--;
            //up
            for(int i=er;i>=sr;--i){
                if(sc<=ec){
                    res.push_back(matrix[i][sc]);
                }
            }
            sc++;
        }
        return res;
    }
};