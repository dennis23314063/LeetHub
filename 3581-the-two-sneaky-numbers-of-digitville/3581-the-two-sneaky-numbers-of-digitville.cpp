class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int x = 0;
        int n = nums.size()-2;
        for(auto &i:nums){
            x ^=i;
        }
        for(int i=0;i<n;i++){
            x ^=i;
        }
        int low_bit = x&-x;
        int a=0,b=0;
        for(auto &i:nums){
            if(i&low_bit)a^=i;
            else b^=i;
        }
        for(int i=0;i<n;i++){
            if(i&low_bit)a^=i;
            else b^=i;
        }
        return {a,b};
    }
};