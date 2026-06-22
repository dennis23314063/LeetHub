class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> v(26,0);
        for(auto &i:text){
            v[i-'a']++;
        }
        return min({v['a'-'a'],v['b'-'a'],v['l'-'a']/2,v['n'-'a'],v['o'-'a']/2});
    }
};