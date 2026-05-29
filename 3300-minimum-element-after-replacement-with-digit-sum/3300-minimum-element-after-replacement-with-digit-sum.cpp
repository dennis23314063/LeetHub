class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = nums[0];
        for(auto &i:nums){
            i = replace(i);
            mn = min(mn,i);
        }
        return mn;
    }
private:
    int replace(int x){
        int ans=0;
        while(x){
            ans+=x%10;
            x/=10;
        }
        return ans;
    }
};