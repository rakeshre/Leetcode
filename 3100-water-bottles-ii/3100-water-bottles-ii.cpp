class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int max_bottles=numBottles;
        int empty=numBottles;
        int exch=0;
        while(numExchange<=empty+exch){
            exch++;
            empty-=numExchange;
            numExchange++;
        }
        return numBottles+exch;
    }
};