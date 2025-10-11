class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> count;
        for(auto &i:power)count[i]++;
        vector<long long> ans;
        ans.reserve(count.size());
        for(auto &[k,v]:count){
            ans.push_back(k);
        }
        sort(ans.begin(),ans.end());
        int n = ans.size();
        vector<long long> dp(n,0);
        dp[0] = ans[0]*count[ans[0]];
        for(int i=1;i<n;i++){
            int index=i-1;
            for(;index>=0&&ans[index]>=ans[i]-2;index--);
            if(index==-1)dp[i] = max(dp[i-1],ans[i]*count[ans[i]]);
            else dp[i] = max(dp[i-1],dp[index]+ans[i]*count[ans[i]]);
            
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<' ';
        // }
        // cout<<endl;
        return dp[n-1];
    }
};