class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum =0;
        for(auto &i:nums){
            sum+=i;
        }
        if(sum%2==0)return nums.size()-1;
        return 0;
    }
};