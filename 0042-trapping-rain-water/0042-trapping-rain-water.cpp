class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=1;i<n;++i){
            left[i]=max(height[i-1],left[i-1]);
        }
        for(int i=n-2;i>=0;--i){
            right[i]=max(height[i+1],right[i+1]);
        }
        int collect=0;
        for(int i=1;i<n-1;++i){
            if(left[i]>height[i] && right[i]>height[i]){
                collect+=min(left[i],right[i])-height[i];
                //cout<<collect<<endl;
            }
        }
        return collect;
    }
};