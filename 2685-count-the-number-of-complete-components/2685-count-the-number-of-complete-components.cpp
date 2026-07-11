class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n);
        parent.resize(n,-1);
        sz.resize(n,1);
        vector<bool>ans(n,true);
        vector<bool>visited(n,false);
        int res=0;

        for(auto &i:edges){
            e[i[0]].push_back(i[1]);
            e[i[1]].push_back(i[0]);
            unionn(i[0],i[1]);
        }
        function<void(int,int)> dfs = [&](int x,int c){
            int m = e[x].size();
            if(m!=c){
                ans[find(x)] = false;
            }
            visited[x] = true;
            for(auto &i:e[x]){
                if(!visited[i])
                    dfs(i,m);
            }
        };
        for(int i=0;i<n;i++){
            if(!visited[find(i)]){
                dfs(i,e[i].size());
                res+=ans[find(i)]&&(e[i].size()==sz[find(i)]-1);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<find(i)<<' ';
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<sz[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<e[i].size()<<' ';
        // }
        return res;
    }
private:
    vector<int>parent;
    vector<int>sz;
    int find(int x){
        return parent[x]==-1?x:parent[x]=find(parent[x]);
    }
    void unionn(int x,int y){
        int rx{find(x)},ry{find(y)};
        if(rx==ry)return;
        if(rx>ry)swap(rx,ry);
        parent[ry] = rx;
        sz[rx]+=sz[ry];
    }
};