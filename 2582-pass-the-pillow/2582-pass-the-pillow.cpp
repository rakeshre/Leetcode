class Solution {
public:
    int passThePillow(int n, int time) {
        bool fr=true;
        while(time>=n){
            time-=(n-1);
            fr=!fr;
        }
        if(fr){
            return time+1;
        }
        return n-time;
    }
};