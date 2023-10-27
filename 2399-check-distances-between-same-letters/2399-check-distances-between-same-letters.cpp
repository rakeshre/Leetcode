class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> ord(26,-1);
        unordered_map<int,int> id;
        int n=s.size();
        for(int i=0;i<n;++i){
            int it=s[i]-'a';
            if(id.find(it)==id.end()){
                id[it]=i;
            }else{
                int d=i-id[it]-1;
                ord[it]=d;
            }
        }
        for(int i=0;i<26;++i){
            cout<<ord[i]<<" ";
        }
        for(int i=0;i<distance.size();++i){
            if(ord[i]==-1){
                    continue;
            }
             if(distance[i]!=ord[i]){
                 return false;
             }
        }
        return true;
    }
};