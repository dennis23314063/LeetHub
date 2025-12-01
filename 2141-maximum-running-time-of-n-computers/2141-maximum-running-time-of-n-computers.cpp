class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0LL;
        sort(batteries.begin(),batteries.end());
        for(auto &i:batteries){
            sum+=i;
        }
        for(int i=batteries.size()-1;i>=0;i--){
            if(batteries[i]>sum/n){
                n--;
                sum-=batteries[i];
            }
        }
        return sum/n;
    }
};