class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        m = heights.size(),n = heights[0].size();
        count.resize(m,vector<int>(n,0));
        cnt.resize(m,vector<int>(n,0));
        if(m==1||n==1){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    ans.push_back({i,j});
                }
            }
            return ans;
        }
        for(int i=0;i<m;i++){
            dfs(heights,i,0,count);
            dfs(heights,i,n-1,cnt);
        }
        for(int i=0;i<n;i++){
            dfs(heights,0,i,count);
            dfs(heights,m-1,i,cnt);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(count[i][j]&&cnt[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
private:
    int m,n;
    vector<vector<int>> count,cnt;
    void dfs(vector<vector<int>>& heights,int x,int y,vector<vector<int>>& c){
        c[x][y] = 1;
        if(x+1<m&&c[x+1][y]==0&&heights[x][y]<=heights[x+1][y])
            dfs(heights,x+1,y,c);
        if(x-1>=0&&c[x-1][y]==0&&heights[x][y]<=heights[x-1][y])
            dfs(heights,x-1,y,c);
        if(y+1<n&&c[x][y+1]==0&&heights[x][y]<=heights[x][y+1])
            dfs(heights,x,y+1,c);
        if(y-1>=0&&c[x][y-1]==0&&heights[x][y]<=heights[x][y-1])
            dfs(heights,x,y-1,c);
    }
};