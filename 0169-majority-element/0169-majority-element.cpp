class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count=0;
        for(auto &i:nums){
            if(count==0){
                candidate = i;
            }
            if(candidate==i){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};