class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
    vector<long long> prefix_sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
    }

    long long max_sum = LLONG_MIN;
    vector<long long> min_prefix(k, LLONG_MAX);
    min_prefix[0] = 0;  // prefix_sum[0]=0, 且 0%k=0

    for (int i = 1; i <= n; i++) {
        int r = i % k;
        if (min_prefix[r] != LLONG_MAX) {
            long long sub_sum = prefix_sum[i] - min_prefix[r];
            if (sub_sum > max_sum) {
                max_sum = sub_sum;
            }
        }
        // 更新此餘數類別遇過的最小 prefix_sum
        if (prefix_sum[i] < min_prefix[r]) {
            min_prefix[r] = prefix_sum[i];
        }
    }

    return max_sum;
        // long long ans=LONG_LONG_MIN;
        // int n = nums.size();
        // vector<long long> dp(n+1,0);
        // for(int i=0;i<n;i++){
        //     dp[i+1] = dp[i]+nums[i];
        // }
        // for(int i=0;i<n+1;i++){
        //     cout<<dp[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=k;i<n+1;i+=k){
        //     ans = max(ans,dp[i]);
        // }
        // return ans;
    }
};