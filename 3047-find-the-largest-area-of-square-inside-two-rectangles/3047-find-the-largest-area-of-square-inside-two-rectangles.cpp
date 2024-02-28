class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        int side=0;
        long long area=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int min_x,min_y,max_x,max_y;
                min_x=max(bottomLeft[i][0],bottomLeft[j][0]);
                min_y=max(bottomLeft[i][1],bottomLeft[j][1]);
                max_x=min(topRight[i][0],topRight[j][0]);
                max_y=min(topRight[i][1],topRight[j][1]);
                int s1=max(max_x-min_x,0);
                int s2=max(max_y-min_y,0);
                side=max(side, min(s1,s2));
                
            }
        }
        area=(long long)side*side;
        return area;
    }
};