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
        long long curr =0;
        for(auto &[_,x]:m){
            if(x<=1)continue;
            curr = x*1LL*(x-1)/2;
            ans+=sum*curr;
            sum+=curr;
        }
        return ans%mod;
    }
};