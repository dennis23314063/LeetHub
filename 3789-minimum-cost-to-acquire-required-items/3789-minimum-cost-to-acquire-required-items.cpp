class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int mx,mn;
        mx = max(need1,need2);
        mn = min(need1,need2);
        long long ans = (long long)cost1*need1+(long long)cost2*need2;
        ans = min(ans,(long long)costBoth*mn+(long long)(need1-mn)*cost1+(long long)(need2-mn)*cost2);
        ans = min(ans,(long long)costBoth*mx);
        return ans;
    }
};