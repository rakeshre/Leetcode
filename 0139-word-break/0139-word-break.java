class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        dp[0]=true;
        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                if(dp[i]==false){
                    dp[i]=dp[j] && (words.find(s.substr(j,i-j))!=words.end());
                }
                
            }
        }
        return dp[n];
        
    }
};