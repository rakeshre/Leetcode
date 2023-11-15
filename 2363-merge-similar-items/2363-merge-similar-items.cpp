class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int> mp;
        for(auto &x:items1){
            int v=x[0];
            mp[v]=x[1];
        }
        for(auto &x:items2){
            int v=x[0];
            if(mp.find(v)==mp.end()){
                mp[v]=x[1];
            }else{
                mp[v]+=x[1];
            }
            
        }
        vector<vector<int>> res;
        for(auto x:mp){
            int k=x.first;
            int v=x.second;
            res.push_back({k,v});
        }
        sort(res.begin(),res.end());
        return res;
    }
};