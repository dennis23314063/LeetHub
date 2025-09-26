class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==0)
                continue;
            for(int j=i+1;j<n-1;j++){
                ans+=lower_bound(nums.begin(),nums.end(),nums[i]+nums[j])-nums.begin()-1-j;
            }
        }
        return ans;
    }
};