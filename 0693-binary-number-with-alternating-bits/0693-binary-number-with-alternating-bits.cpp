class Solution {
public:
    bool hasAlternatingBits(int n) {
        int count;
        int low = n&(-n);
        if(n%2)count=0;
        else if(low==2)count=1;
        else return false;
        while(n){
            if(low!=(1<<count))return false;
            n-=low;
            count+=2;
            low = n&(-n);
        }
        return true;

    }
};