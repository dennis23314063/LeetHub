class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;){
            int j=i;
            while(j<n&&s[j]==s[i])j++;
            ans = max(ans,j-i);
            i=j;
        }
        auto check = [&](char x,char y,char z){
            for (int i = 0; i < n;)
            {
                if (s[i] == z)
                {
                    ++i;
                    continue;
                }
                int j = i;
                while (j < n && s[j] != z)
                    ++j;
                unordered_map<int, int> first;
                first.reserve(j - i + 1);
                first.max_load_factor(0.7f);
                int pref = 0;
                first[0] = i - 1;
                for (int k = i; k < j; ++k)
                {
                    pref += (s[k] == x) - (s[k] == y);
                    auto it = first.find(pref);
                    if (it != first.end())
                        ans = max(ans, k - it->second);
                    else
                        first.emplace(pref, k);
                }
                i = j;
            }
        };
        check('a','b','c');
        check('a','c','b');
        check('b','c','a');
        unordered_map<long long,int>mp;
        mp[0] = -1;
        int a=0,b=0,c=0;
        auto pack = [&](int x, int y){
            return ((long long)x << 32) ^ unsigned(y); 
        };
        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;
            long long key = pack(a-b,a-c);
            if(mp.count(key))ans=max(ans,i-mp[key]);
            else mp[key] = i;
        }
        return ans;
    }
};