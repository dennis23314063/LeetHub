class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0,res=0;
        while(numBottles){
            ans+=numBottles;
            res += numBottles%numExchange;
            numBottles /= numExchange;
            if(res>=numExchange){
                numBottles+=res/numExchange;
                res%=numExchange;
            }
        }
        return ans;
    }
};