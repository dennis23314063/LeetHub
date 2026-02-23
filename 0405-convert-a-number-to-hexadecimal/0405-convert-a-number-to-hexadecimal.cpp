class Solution {
public:
    string toHex(unsigned num) {
        char ans[9];
        sprintf(ans,"%x",num);
        return ans;
        
    }
};