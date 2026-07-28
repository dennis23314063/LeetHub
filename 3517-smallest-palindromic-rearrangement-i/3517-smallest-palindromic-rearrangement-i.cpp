class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26,0);
        for(auto &i:s)v[i-'a']++;
        string ans=s;
        int n = ans.size();
        for(int i=0,j=0;i<26;i++){
            if(v[i]%2)ans[n/2]=(char)(i+'a');
            v[i]/=2;
            while(v[i]--)ans[j] = ans[n-j-1] = (char)(i+'a'),j++;
        }
        return ans;
    }
};