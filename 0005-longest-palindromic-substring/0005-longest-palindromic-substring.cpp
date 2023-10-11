class Solution {
public:
    
    bool dfs(string& s, int st, int e, vector<vector<int>> &dp){
        int n=s.size();
        if(st>=n && e<0){
            return false;
        }
        if(dp[st][e]!=-1){
            return dp[st][e];
        }
        if(st==e){
            dp[st][e]=1;
            return true;
        }
        if(e==st+1 && s[st]==s[e]){
            dp[st][e]=1;
            return true;
        }
        if(s[st]==s[e]){
            bool res=dfs(s, st+1, e-1, dp);
            if(res==true){
                dp[st][e]=1;
                return true;
            }
        }
        dfs(s, st, e-1, dp);
        dfs(s, st+1, e, dp);
        dp[st][e]=0;
        return false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int st=0;
        int e=n-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        dfs(s, st, e, dp);
        int maxlen=-1;
        int st_i=0;
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                if(dp[i][j]==1){
                   if(j-i+1>maxlen){
                       st_i=i;
                       maxlen=j-i+1;
                   }
                }
            }
        }
        return s.substr(st_i,maxlen);
    }
};