class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int applesize=0;
        for(int i=0;i<apple.size();++i){
            applesize+=apple[i];
        }
        sort(capacity.begin(),capacity.end(),greater<>());
        int check_sum=0;
        for(int i=0;i<capacity.size();++i){
            check_sum+=capacity[i];
            if(check_sum>=applesize){
                return i+1;
            }
        }
        return capacity.size();
    }
};