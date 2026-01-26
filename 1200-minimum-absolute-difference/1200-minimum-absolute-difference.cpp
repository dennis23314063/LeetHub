class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<int> diffarr(arr.begin(),arr.end());
        sort(diffarr.begin(),diffarr.end());
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            diffarr[i] = diffarr[i+1]-diffarr[i];
        }
        diffarr.pop_back();
        vector<vector<int>> ans;
        sort(diffarr.begin(),diffarr.end());
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==diffarr[0]){
                ans.push_back(vector<int>{arr[i],arr[i+1]});
            }
        }
        return ans;

    }
};