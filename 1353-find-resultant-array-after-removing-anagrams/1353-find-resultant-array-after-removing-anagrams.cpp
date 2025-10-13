class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        vector<int> count(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                count[i]+=(1<<(words[i][j]-'a'));
            }
        }
        for(int i=1;i<n;i++){
            if(count[i]!=count[i-1])ans.push_back(words[i]);
        }
        return ans;
    }
};