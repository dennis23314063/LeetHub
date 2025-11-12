class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans=n;
        int g = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==1)ans--;
            g = __gcd(g,nums[i]);
        }
        if(g!=1)return -1;
        if(ans!=n){
            return ans;
        }
        for(int i=0;i<n;i++){
            g = nums[i];
            for(int j=i+1;j<n;j++){
                g = __gcd(nums[j],g);
                if(g==1){
                    ans = min(ans,j-i-1);
                    break;
                }
            }
        }
        return n+ans;
    }
};