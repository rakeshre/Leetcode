class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>> pq;
        //when a vector is pushed into priority queue, it is sorted based on the first element.
        for(auto x:points){
            int d=x[0]*x[0]+x[1]*x[1];
            pq.push({d,x[0],x[1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        for(int i=0;i<k;++i){
            vector<int> pt=pq.top();
            pq.pop();
            res.push_back({pt[1],pt[2]});
        }
        return res;
    }
};