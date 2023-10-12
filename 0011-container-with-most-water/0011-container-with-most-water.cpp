class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int st=0, e=n-1;
        int area=0;
        while(st<e){
            int min_l=min(height[st],height[e]);
            area=max(area, min_l*(e-st));
            if(height[st]<height[e]){
                st++;
            }else{
                e--;
            }
        }
        return area;
    }
};