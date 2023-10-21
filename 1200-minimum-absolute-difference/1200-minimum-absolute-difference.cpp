class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int diff=INT_MAX;
        vector<vector<int>> res;
        for(int i=1;i<n;++i){
            int d=abs(arr[i]-arr[i-1]);
            if(d<diff){
                res.clear();
                diff=d;
                res.push_back({arr[i-1],arr[i]});
            }else if(d==diff){
                res.push_back({arr[i-1],arr[i]});
            }
        }
        return res;
    }
};