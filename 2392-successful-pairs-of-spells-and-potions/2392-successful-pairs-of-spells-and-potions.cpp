class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        for(auto &i:spells){
            long long k = (success+i-1)/(i*1LL);
            int it = n-(lower_bound(potions.begin(),potions.end(),k)-potions.begin());
            i = it;
        }
        return spells;
    }
};