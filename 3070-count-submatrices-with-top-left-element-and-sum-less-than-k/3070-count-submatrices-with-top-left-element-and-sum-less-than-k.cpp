class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> gridSum=grid;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        if(grid[0][0]<=k){
            count++;
        }
        for(int i=1;i<m;++i){
            gridSum[i][0]+=gridSum[i-1][0];
            if(gridSum[i][0]<=k){
                count++;
            }
        }
        for(int j=1;j<n;++j){
            gridSum[0][j]+=gridSum[0][j-1];
            if(gridSum[0][j]<=k){
                count++;
            }
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                gridSum[i][j]+=gridSum[i-1][j]+gridSum[i][j-1]-gridSum[i-1][j-1];
                if(gridSum[i][j]<=k){
                    count++;
                }
            }
        }
        return count;
    }
};