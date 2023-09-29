class Solution {
public:
    //dfs doesn't work because it goes depth
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ttr=0,c=0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    c++;
                }
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> ir{0,-1,0,1};
        vector<int> ic{1,0,-1, 0};
        int oc=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            ttr=max(ttr,t);
            q.pop();
            for(int i=0;i<4;++i){
                int nr=r+ir[i];
                int nc=c+ic[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},t+1});
                    oc++;
                }
            }
        }
        if(c!=oc){
            return -1;
        }
        return ttr;
    }
};