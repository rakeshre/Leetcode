class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j){
        int n=word.size();
        int x=board.size();
        int y=board[0].size();
        if(n==0){
            return true;
        }
        if(i<0 || i>=x || j<0 || j>=y|| board[i][j]!=word[0]){
            return false;
        }
        char ch=board[i][j];
        string tr_w=word.substr(1, n-1);
        board[i][j]='*'; //important as it prevent unlimited recursion.
            bool res = dfs(board, tr_w, i+1,j)|| dfs(board, tr_w, i,j+1)|| dfs(board, tr_w, i-1,j) || dfs(board, tr_w, i,j-1);
            board[i][j]=ch;
            return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                bool res=dfs(board,word,i,j);
                if(res==true){
                    return true;
                }
            }
        }
        return false;
    }
};