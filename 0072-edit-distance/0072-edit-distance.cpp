class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // if(word1.size()==0){
        //     return word2.size();
        // }
        // if(word2.size()==0){
        //     return word1.size();
        // }
        // if(word1[0]==word2[0]){
        //     dp[0][0]=0;
        // }else{
        //     dp[0][0]=1;
        // }
        // for(int i=;i<m;++i){
        //     if(word1[i]==word2[0]){
        //         dp[i][0]=dp[i-1][0];
        //     }else{
        //         dp[i][0]=dp[i-1][0]+1;
        //     }
        // }
        // for(int j=1;j<n;++j){
        //     if(word2[j]==word1[0]){
        //         dp[0][j]=dp[0][j-1];
        //     }else{
        //         dp[0][j]=dp[0][j-1]+1;
        //     }
        // }
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i==0){
                    dp[i][j]=j;
                }else if(j==0){
                    dp[i][j]=i;
                }else if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
                
            }
        }
        return dp[m][n];
    }
};