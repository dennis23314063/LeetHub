class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int ans = 0;
        for(auto &i:prices){
            mn = min(i,mn);
            ans = max(ans,i-mn);
        }
        return ans;

    }
};