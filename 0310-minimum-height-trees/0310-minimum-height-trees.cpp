class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>> graph(n);//of size n should be used.
        vector<int> indegree(n,0);
        vector<int> res;
        for(auto &list:edges){
            graph[list[0]].push_back(list[1]);
            graph[list[1]].push_back(list[0]);
            indegree[list[0]]++;
            indegree[list[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;++i){
            if(indegree[i]==1){
                q.push(i);
                indegree[i]--;
            }
        }
        while(!q.empty()){
            int sz=q.size();//imp to define here. i mean are u dumb?
            res.clear();
            for(int i=0;i<sz;++i){
                int cur=q.front();
                q.pop();
                res.push_back(cur);
                for(auto &val:graph[cur]){
                    indegree[val]--;
                    if(indegree[val]==1){
                        q.push(val);
                    }
                }
            }
            
        }
        return res;
    }
};