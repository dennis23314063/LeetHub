class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto &i:grid){
            for(auto &j:i)arr.push_back(j);
        }
        int n=arr.size();
        if(n==1)return 0;
        sort(arr.begin(),arr.end());
        int min = arr[0];
        int times=0;
        int median = arr[n/2];
        for(auto &i:arr){
            if((i-min)%x!=0)return -1;
            times+=abs(i-median)/x;
        }
        return times;

    }
};