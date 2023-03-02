class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> distance(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int nextRow[]={-1,0,+1,0};
        int nextCol[]={0,+1,0,-1};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                    distance[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            
            //distance[x][y]=d;
            for(int i=0;i<4;++i){
                int xi=x+nextRow[i];
                int yi=y+nextCol[i];
                if(xi>=0 && xi<m && yi>=0 && yi<n && !visited[xi][yi]){
                    visited[xi][yi]=1;
                    distance[xi][yi]=d+1;
                    q.push({{xi,yi},d+1});
                }
            }
            q.pop();
            
        }
        return distance;
    }
};