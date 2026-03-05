class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        bool check = true;
        for(auto i:s){
            if(check&&i=='0'||!check&&i=='1')ans++;
            check = !check;
        }
        return std::min(ans,(int)s.size()-ans);
    }
};