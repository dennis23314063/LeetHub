class Solution {
public:
    bool canAliceWin(int n) {
        //10 19 27 34 40 45 49 52 54 55
        int win[] = {0,10,19,27,34,40,45,49,52};
        for(int i=1;i<9;i++){
            if(win[i-1]<=n&&win[i]>n){
                return (i%2==0);
            }
        }
        return false;
    }
};