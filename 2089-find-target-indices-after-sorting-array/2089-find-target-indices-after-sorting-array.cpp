class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int times=0;
        int low=0;
        for(auto &i:nums){
            if(i<target)low++;
            else if(i==target)times++;
        }
        for(int i=0;i<times;i++){
            ans.push_back(low+i);
        }
        return ans;

    }
};