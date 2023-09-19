class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int high=-1;
        for(int i=0;i<intervals.size();++i){
            vector<int> curr=intervals[i];
            //before new interval
            if(curr[1]<newInterval[0]){
                ans.push_back(curr);
                high=curr[1];
            }else if(curr[0]>newInterval[1]){
                //after intervals
                if(!newInterval.empty()){
                    ans.push_back(newInterval);
                    newInterval={};
                }
                
                ans.push_back(curr);
            }else{
                //overlapping
                newInterval[0]=min(newInterval[0],curr[0]);
                newInterval[1]=max(newInterval[1],curr[1]);
                
            }
        }
        if(newInterval[0]>high && !newInterval.empty()){
            ans.push_back(newInterval);
        }
        return ans;

    }
};