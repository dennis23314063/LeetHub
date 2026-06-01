class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0;
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater());
        for(int i=0,j=0;i<n;i++){
            ans+=cost[i];
            j++;
            if(j==3)ans-=cost[i];
            j%=3;
        }
        return ans;
    }
};