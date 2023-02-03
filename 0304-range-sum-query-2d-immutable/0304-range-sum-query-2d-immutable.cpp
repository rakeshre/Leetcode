class NumMatrix {
public:
    vector<vector<int>> &p_sum;
    NumMatrix(vector<vector<int>>& matrix) : p_sum(matrix){
        int m=p_sum.size();
        int n=p_sum[0].size();
        for(int i=1;i<m;++i){
            p_sum[i][0]+=p_sum[i-1][0];
        }
        for(int j=1;j<n;++j){
            p_sum[0][j]+=p_sum[0][j-1];
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                int cum=p_sum[i-1][j]+p_sum[i][j-1]-p_sum[i-1][j-1];
                p_sum[i][j]+=cum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /*
        if(row1==0 && col1==0){
            return p_sum[row2][col2];
        }
        */
        int ans= p_sum[row2][col2]-(col1>=1? p_sum[row2][col1-1]: 0)-(row1>=1? p_sum[row1-1][col2]:0)+((row1>=1 && col1>=1) ? p_sum[row1-1][col1-1]: 0);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */