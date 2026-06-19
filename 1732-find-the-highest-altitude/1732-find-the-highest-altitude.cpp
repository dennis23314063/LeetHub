class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx =0;
        int curr=0;
        for(auto &i:gain){
            curr+=i;
            mx = max(curr,mx);
        }
        return mx;
    }
};