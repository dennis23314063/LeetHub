class Solution {
public:
    int bitwiseComplement(int n) {
        int count=0;
        if(n==0)return 1;
        while(n>=(1<<count))count++;
        int k = (1<<count)-1;
        return k^n;
    }
};