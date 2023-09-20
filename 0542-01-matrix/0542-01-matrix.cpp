class Solution {
public:
    bool isSafe(vector<vector<int>>& mat, int x,int y){
        int m=mat.size();
        int n=mat[0].size();
        if(x>=0 && x<m && y>=0 && y<n){
            return true;
        }
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        vector<pair<int,int>> dist{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto pr=q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int xi=pr.first+dist[i].first;
                int yi=pr.second+dist[i].second;
                if(isSafe(mat,xi,yi) && mat[xi][yi]>mat[pr.first][pr.second]+1){
                    mat[xi][yi]=mat[pr.first][pr.second]+1;
                    q.push({xi,yi});
                }
            }
        }
        return mat;
    }
};