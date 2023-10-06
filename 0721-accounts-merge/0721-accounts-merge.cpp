class Solution {
public:
    unordered_map<string, vector<string>> mp;
    unordered_set<string> vis;
    void dfs(vector<string>& mergeAccount, string mailId){
        if(vis.find(mailId)==vis.end()){
            vis.insert(mailId);
            mergeAccount.push_back(mailId);
            for(auto &neighbor: mp[mailId]){
                dfs(mergeAccount,neighbor);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> mergedAccounts;
        for(auto &account: accounts){
            int n=account.size();
            string mail=account[1];
            //vis.insert(mail);-> visited only while traversal
            //mp[mail]={};
            for(int i=2;i<n;++i){
                string ac=account[i];
                mp[mail].push_back(ac);
                mp[ac].push_back(mail);
            }
        }
        
        for(auto &account:accounts){
            vector<string> acc;
            string acc_name=account[0];
            acc.push_back(acc_name);
            string first_mail=account[1];
            dfs(acc, first_mail);
            if(acc.size()>=2){
                sort(acc.begin()+1,acc.end());
                mergedAccounts.push_back(acc);
            }
        }
        return mergedAccounts;
        
    }
};