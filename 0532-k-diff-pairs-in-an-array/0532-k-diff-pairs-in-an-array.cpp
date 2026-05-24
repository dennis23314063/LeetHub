class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto i:nums)mp[i]++;
        for(auto &[key,v]:mp){
            if(k==0){
                ans+=(mp[key]>1);
                continue;
            }
            if(mp.find(key-k)!=mp.end())ans+=mp[key-k]!=0;
            if(mp.find(key+k)!=mp.end())ans+=mp[key+k]!=0;
            mp[key]=0;
        }
        return ans;
    }
};