class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int,int>> p;
        int n = s.size();
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(p.empty()||p.back().second!=i-1)
                    p.push_back({i,i});
                else
                    p.back().second = i;
            }
            else{
                one++;
            }
        }
        if(p.empty())return n;
        if(p.size()==1)return n-(p[0].second-p[0].first+1);
        int ans=0;
        int m = p.size();
        for(int i=0;i<m-1;i++){
            int a = p[i].second-p[i].first+1;
            int b = p[i+1].second-p[i+1].first+1;
            ans = max(ans,one+a+b);
        }
        return ans;
    }
};