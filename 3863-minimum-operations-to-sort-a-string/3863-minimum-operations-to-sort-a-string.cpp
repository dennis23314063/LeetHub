class Solution {
public:
    int minOperations(string s) {
        if(s.size()==2&&s[0]>s[1]){
            return -1;
        }
        char mn =s[0];
        char mx = s[0];
        bool zero = true;
        vector<int> count(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            mn = min(mn,s[i]);
            mx = max(mx,s[i]);
            count[s[i]-'a']++;
            if(i>0&&s[i]<s[i-1])zero=false;
        }
        if(zero)return 0;
        else if(s[0]==mx&&s[n-1]==mn&&count[s[0]-'a']==1&&count[s[n-1]-'a']==1)return 3;
        else if(s[0]==mn||s[n-1]==mx)return 1;
        return 2;
    }
};