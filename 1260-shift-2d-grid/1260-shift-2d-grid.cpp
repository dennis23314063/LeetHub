class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> new_grid = grid;
        int n = grid.size();
        int m = grid[0].size();
        k%=n*m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx = (i*m+j-k+n*m)%(n*m);
                new_grid[i][j] = grid[idx/m][idx%m];
            }
        }
        return new_grid;
    }
};