class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans =1e9+7;
        int n = triangle.size();
        for(int i=1;i<n;i++){
            triangle[i][0] +=triangle[i-1][0]; 
            for(int j=1;j<i;j++){
                triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
            }
            triangle[i][i]+=triangle[i-1][i-1];
        }
        for(int i=0;i<n;i++){
            ans = min(triangle[n-1][i],ans);
        }
        return ans;
    }
};