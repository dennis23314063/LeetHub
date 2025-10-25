class Solution {
public:
    int totalMoney(int n) {
        int div = n/7;
        int mod = n%7;
        int ans = div*28+div*(div-1)/2*7;
        ans+=mod*div+(1+mod)*mod/2;
        return ans;
    }
};