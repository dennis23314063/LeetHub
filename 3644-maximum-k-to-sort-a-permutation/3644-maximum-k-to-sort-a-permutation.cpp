class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=2147483647;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==i)continue;
            ans&=nums[i];
        }
        if(ans==2147483647)return 0;
        return ans;
    }
};