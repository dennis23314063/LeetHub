class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n,false);
        ans[0] = nums[0]==0;
        for(int i=1;i<n;i++){
            nums[i] = nums[i-1]*2%5+nums[i];
            nums[i]%=5;
            ans[i] = nums[i]%5==0;
        }
        return ans;
    }
};