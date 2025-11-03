class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans=0;
        for(int i=0;i<n;){
            int temp = i;
            int next = i+1;
            while(next<n&&colors[next]==colors[temp]){
                if(neededTime[temp]<neededTime[next]){
                    ans+= neededTime[temp];
                    temp = next;
                }
                else{
                    ans+=neededTime[next];
                }
                next++;
            }
            i = next;
        }
        return ans;
    }
};