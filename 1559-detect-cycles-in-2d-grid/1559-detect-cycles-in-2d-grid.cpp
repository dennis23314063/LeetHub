class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        char curr='0';
        function<bool(int,int,int,int)> dfs = [&](int x,int y,int px,int py){
            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,1,-1};
            bool ans=false;
            if(visited[y][x]&&curr==grid[y][x]){
                return true;
            }
            visited[y][x] = true;
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||nx>=col||ny<0||ny>=row||(nx==px&&ny==py))continue;
                if(grid[ny][nx]!=curr)continue;
                ans|=dfs(nx,ny,x,y);
            }
            return ans;
        };
        auto print = [&](){
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cout<<visited[i][j]<<" \n"[j==col-1];
                }
            }
        };
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                curr = grid[i][j];
                if(!visited[i][j]&&dfs(j,i,-1,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};