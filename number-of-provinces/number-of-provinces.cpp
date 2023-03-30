#include<bits/stdc++.h>
class UnionFind{
    public:
     UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x, int y){
        int x_par=find(x);
        int y_par=find(y);
        if(x_par!=y_par){
            if(rank[x_par]>rank[y_par]){
                parent[y_par]=x_par;
            }else if(rank[y_par]>rank[x_par]){
                parent[x_par]=y_par;
            }else{
                parent[y_par]=x_par;
                ++rank[x_par];
            }
        }
    }
    private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        UnionFind uf(m);
        
        for(int i=0;i<m;++i){
            for(int j=i+1;j<m;++j){
                if(isConnected[i][j]==1){
                    uf.unionSet( i,j);
                }
            }
        }
        unordered_set<int> comp;
        for(int i=0;i<m;++i){
            comp.insert(uf.find(i));
        }
        return comp.size();
        
    }
};