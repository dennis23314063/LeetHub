class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int n = matrix.size();
        long long sum =0;
        int count=0;
        int zero=0;
        long long mn=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    count++;
                    sum+=abs(matrix[i][j]);
                }
                else{
                    if(matrix[i][j]==0)zero++;
                    ans+=matrix[i][j];
                }
                mn = min(mn,abs(matrix[i][j])*1LL);
            }
        }
        if(count%2){
            if(zero>0){
                ans+=sum;
            }
            else{
                ans+=sum-2*mn;
            }
        }
        else{
            ans+=sum;
        }
        return ans;
    }
};