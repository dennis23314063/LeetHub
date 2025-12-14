class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int>v;
        long long ans = 1;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S')v.push_back(i);
        }
        n = v.size();
        if(n%2||n==0)return 0;
        for(int i=2;i<n;i+=2){
            ans*=v[i]-v[i-1];
            ans%=mod;
        }
        return ans;
    }
};