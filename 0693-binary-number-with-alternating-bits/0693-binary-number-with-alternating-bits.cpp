class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int x = n^(n>>1);
        cout<<x<<endl;
        return (x&(x+1))==0;
    }
};