class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int a=intervals[0][0];
        int b=intervals[0][1];
        for(int i=1;i<n;++i){
             if(intervals[i][0]<=b){
                 b=max(b,intervals[i][1]);
             }else{
                 res.push_back({a,b});
                 a=intervals[i][0];
                 b=intervals[i][1];
             }
        }
        res.push_back({a,b});
        return res;
    }
};