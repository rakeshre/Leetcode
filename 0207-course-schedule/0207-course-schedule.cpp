class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjList(numCourses,vector<int>{});
        queue<int> q;
        for(auto prereq: prerequisites){
            int a=prereq[0];
            int b=prereq[1];
            indegree[a]++;
            adjList[b].push_back(a);
        }
        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int visitedNodes=0;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            visitedNodes++;
            for(auto x: adjList[num]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        return visitedNodes == numCourses;
    }
};