class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = 0;
        int ans = 0;
        bool check = false;
        int mn = INT_MIN;
        for(auto i:nums){
            if(i>=0)check = true;
            else mn = max(mn,i);
            mx = max(mx+i,0);
            ans = max(mx,ans);
        }
        if(!check)return mn;
        return ans;

    }
};