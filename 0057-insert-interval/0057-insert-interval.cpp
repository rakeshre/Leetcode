class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int n=intervals.size();
//         vector<vector<int>> intervals_new;
//         int st=-1;
//         for(int i=0;i<n;++i){
//             if(intervals[i][1]<newInterval[0]){
//                 intervals_new.push_back(intervals[i]);
//             }else{
//                 st=intervals[i][0];
//             }
            
//         }
//     }
          vector<vector<int>>ans;

        // 2 cases.
        for(auto currentInterval:intervals){
        //case 1 :non overlapping
        // new interval is after current interval. add current interval to the ans.
        if(currentInterval[1]<newInterval[0]){ans.push_back(currentInterval);}
        // if new interval comes before current interval that means we need to make it current interval and check for overlaping with others. And our new interval will also be add to ans.
        else if(newInterval[1]<currentInterval[0]){
                    ans.push_back(newInterval);
                    //update it to new interval for overlapping checking.
                    newInterval = currentInterval;
        }
        // case 2 :overlapping
        else{
            // update the newInterval for checking overlapping.
            newInterval[0] = min(currentInterval[0],newInterval[0]);
            newInterval[1] = max(currentInterval[1],newInterval[1]);

        }

        }
        // Add the last non overlaping interval (newInterval)
        ans.push_back(newInterval);

        return ans;


    }
};