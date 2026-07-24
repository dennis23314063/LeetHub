class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> one(2048,false);
        vector<bool> two(2048,false);
        vector<bool> three(2048,false);
        int ans =0;
        for(int i=0;i<n;i++){
            one[nums[i]] = true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<2048;j++){
                if(one[j])
                    two[nums[i]^j] = true;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<2048;j++){
                if(two[j])
                    three[nums[i]^j] = true;
            }
        }
        for(int i=0;i<2048;i++)ans+=three[i];
        return ans;

    }
};