class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int ans=0;
        int mod = 1000000007;
        for(int i=0,cnt=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
                ans+=cnt;
                ans%=mod;
            }
            else{
                cnt = 0;
            }
        }
        return ans;
    }
};