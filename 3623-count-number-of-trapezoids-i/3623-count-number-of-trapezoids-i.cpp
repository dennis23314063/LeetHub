class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> m;
        for(auto &i:points){
            m[i[1]]++;
        }
        int mod = 1e9+7;
        long long ans = 0;
        long long sum= 0;
        for(auto &[_,x]:m){
            if(x<=1)continue;
            ans+=sum*x*(x-1)/2LL;
            sum+=x*1LL*(x-1)/2LL;
        }
        return ans%mod;
    }
};