class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum =0;
        int acc = 0;
        int ans = 0;
        for(auto &i:nums){
            sum+=i;
            // if(sum%2==0)ans++;
        }
        for(auto &i:nums){
            acc+=i;
            ans+=(sum-2*acc)%2==0;
        }
        return max(0,ans-1);
    }
};