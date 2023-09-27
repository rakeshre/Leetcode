class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nr=grid.size();
        int nc=grid[0].size();
         grid[r][c]='0';
         if(r-1>=0 && grid[r-1][c]=='1'){dfs(grid,r-1,c);}
         if(c-1>=0 && grid[r][c-1]=='1'){dfs(grid,r,c-1);}
         if(r+1<nr && grid[r+1][c]=='1'){dfs(grid,r+1,c);}
         if(c+1<nc && grid[r][c+1]=='1'){dfs(grid,r,c+1);}
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIslands=0;
      int r=grid.size();
      int c=grid[0].size();
      for(int i=0;i<r;++i){
          for(int j=0;j<c;++j){
              if(grid[i][j]=='1'){
                  numIslands++;
                  dfs(grid, i,j);
              }
              
          }
      }
        return numIslands;
    }
};