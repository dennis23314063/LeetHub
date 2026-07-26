class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=-1e9;
        int n = nums.size();
        ans = max(ans,nums[n-1]*nums[n-2]*nums[n-3]);
        ans = max(ans,nums[n-1]*nums[1]*nums[0]);
        return ans;
    }
};