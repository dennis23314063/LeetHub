class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        auto rot = [&](){
            vector<vector<int>> new_v = mat;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    new_v[i][j] = mat[n-1-j][i];
                }
            }
            mat = new_v;
            return;
        };
        for(int i=0;i<4;i++){
            if(mat==target)return true;
            rot();
        }
        return false;
        
    }
};