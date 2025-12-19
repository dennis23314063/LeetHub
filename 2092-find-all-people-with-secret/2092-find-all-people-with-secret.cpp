class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),[](auto &a,auto &b){
            if(a[2]==b[2]){
                if(a[0]==b[0])return a[1]<b[1];
                return a[0]<b[0];
            }
            return a[2]<b[2];
        });
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        function<int(int)> find = [&](int x){
            return parent[x] == x? x:parent[x] = find(parent[x]);
        };
        auto unionn =[&](int x,int y){
            int rx = find(x);
            int ry = find(y);
            if(rx==ry)return;
            if(rx>ry)swap(rx,ry);
            parent[ry] = rx;
        };
        parent[firstPerson] = 0;
        // for(int i=0;i<meetings.size();i++){
        //     printf("%d %d %d\n",meetings[i][0],meetings[i][1],meetings[i][2]);
        // }
        for(int i=0;i<meetings.size();i++){
            int j=i;
            for(;j<meetings.size()&&meetings[i][2]==meetings[j][2];j++){
                unionn(meetings[j][0],meetings[j][1]);
            }
            for(int k=i;k<j;k++){
                if(find(meetings[k][0])!=0)parent[meetings[k][0]] = meetings[k][0];
                if(find(meetings[k][1])!=0)parent[meetings[k][1]] = meetings[k][1];
            }
            i = j-1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(parent[i]==0)ans.push_back(i);
        }
        return ans;
        
    }
};