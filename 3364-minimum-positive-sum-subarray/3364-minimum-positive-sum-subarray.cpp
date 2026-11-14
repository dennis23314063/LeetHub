class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=1e9;
        int n = nums.size();

        int temp=0;
        for(int i=0;i<n;i++){
            temp=0;
            for(int j=i;j<n;j++){
                int len = j-i+1;
                temp+=nums[j];
                if(len>=l&&len<=r&&temp>0)ans = min(ans,temp);
                if(len>r)break;
            }
        }
        if(ans==(int)1e9)return -1;
        return ans;
    }
};