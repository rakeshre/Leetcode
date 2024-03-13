class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        long long sum=0;
        int cut=0;
        for(int i=0;i<k;++i){
            int val=happiness[i]-cut;
            if(val<0){
                break;
            }
            sum+=val;
            cut++;
        }
        return sum;
    }
};